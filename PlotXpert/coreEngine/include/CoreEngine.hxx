#pragma once

#include <map>
#include <mutex>
#include <string>
#include <vector>

#include <Cache.hxx>
#include <Operation.hxx>
#include <OperationResult.hxx>
#include <OperationContext.hxx>
#include <OperationRegistrant.hxx>


class CoreEngine {
public:
	static CoreEngine* getInstance();
	~CoreEngine() = default;

	// Methods
	OperationResult execute(IOperationContext* context);

private:
	std::string generateCacheKey(const IOperationContext& context);

	// Constructors
	CoreEngine();

	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;

	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;

	// Data members
	static CoreEngine* m_instance;
	static std::mutex m_mutex;

	OperationRegistrant* m_operationRegistrant;

	// If the operands & operation are in the cache, means we do not have to perform calculation again, find the unique key to get the result directly.
	Cache<std::string, std::shared_ptr<OperationResult>> m_resultCache;
};
