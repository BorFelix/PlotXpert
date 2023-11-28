#pragma once

#include <list>
#include <mutex>
#include <unordered_map>

template<class Key, class Value>
class Cache {
public:
	explicit Cache(size_t capacity) : m_capacity(capacity), m_mutex() {}

	Value get(const Key& key);
	void put(const Key& key, Value value);
	void remove(const Key& key);
	bool contains(const Key& key) const;

private:
	//Tracks the order of usage of keys, easy to process the least/most recently used Key
	//The most recently used key is at the front, and the least recently used key is at the back.
	std::list<Key> m_lruList;
	std::unordered_map<Key, std::pair<Value, typename std::list<Key>::iterator>> m_cacheMap;
	size_t m_capacity; // Maximum number of items the cache can hold
	mutable std::mutex m_mutex; // Mutex for thread safety

	void updateMRUKey(const Key& key); // Updates the usage order of a key
	void evict(); // Evicts the least recently used item
};

template<class Key, class Value>
Value Cache<Key, Value>::get(const Key& key) 
{
	std::lock_guard<std::mutex> lock(m_mutex);
	auto it = m_cacheMap.find(key);
	if (it != m_cacheMap.end()) {
		updateMRUKey(key); // Update the usage order
		return it->second.first;
	}
	return nullptr; // Or throw an exception or handle the missing key differently
}

template<class Key, class Value>
void Cache<Key, Value>::put(const Key& key, Value value) 
{
	std::lock_guard<std::mutex> lock(m_mutex);
	auto it = m_cacheMap.find(key);
	if (it != m_cacheMap.end()) {
		// Replace the value and update the usage order
		it->second.first = std::move(value);
		updateMRUKey(key);
	}
	else {
		if (m_cacheMap.size() >= capacity) {
			evict(); // Evict the least recently used item
		}
		m_lruList.push_front(key);
		m_cacheMap[key] = { std::move(value), m_lruList.begin() };
	}
}

template<class Key, class Value>
void Cache<Key, Value>::remove(const Key& key) 
{
	std::lock_guard<std::mutex> lock(m_mutex);

	auto it = m_cacheMap.find(key);
	if (it != m_cacheMap.end()) {
		m_lruList.erase(it->second.second);
		m_cacheMap.erase(it);
	}
}

template<class Key, class Value>
bool Cache<Key, Value>::contains(const Key& key) const 
{
	std::lock_guard<std::mutex> lock(m_mutex);

	return m_cacheMap.find(key) != m_cacheMap.end();
}

template<class Key, class Value>
void Cache<Key, Value>::updateMRUKey(const Key& key) 
{
	std::lock_guard<std::mutex> lock(m_mutex);

	auto it = m_cacheMap.find(key);
	if (it != m_cacheMap.end())
	{
		m_lruList.erase(it->second.second);		//Remove old address of the key in list
		m_lruList.push_front(key);				//Make the key at the front of list
		it->second.second = m_lruList.begin();	//Update the most recently used key address in the m_cacheMap
	}
}

template<class Key, class Value>
void Cache<Key, Value>::evict() 
{
	std::lock_guard<std::mutex> locker(m_mutex);

	m_cacheMap.erase(m_lruList.back()); //get the key value of LRU in list, and then remove the key-vlaue pair in map based on key
	m_lruList.pop_back();	//remove the LRU address in list
}