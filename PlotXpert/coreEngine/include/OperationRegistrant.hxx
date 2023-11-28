#pragma once

#include <mutex>
#include <unordered_map>

#include <Operation.hxx>

class OperationRegistrant
{
public:
	static OperationRegistrant* getInstance();

	void registorOperation(std::unique_ptr<IOperation> operation);
	
	IOperation* getOperation(const OperationType& operType);


private:
	static OperationRegistrant* m_instance;
	static std::mutex m_mutex;

	OperationRegistrant() = default;
	OperationRegistrant(const OperationRegistrant&) = delete;
	OperationRegistrant(OperationRegistrant&&) = delete;
	OperationRegistrant& operator=(const OperationRegistrant&) = delete;
	OperationRegistrant& operator=(OperationRegistrant&&) = delete;

	std::unordered_map<OperationType, std::unique_ptr<IOperation>> m_operations;

};