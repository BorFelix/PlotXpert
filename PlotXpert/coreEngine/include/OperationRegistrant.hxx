#pragma once

#include <map>
#include <string>
#include <Operation.hxx>

class OperationRegistrant
{
public:
	OperationRegistrant& getInstance()
	{
		static OperationRegistrant instance;
		return instance;
	}

	void registorOperation(IOperation* operation)
	{
		operations[operation->getType()] = operation;
	}	
	
	IOperation* getOperation(OperationType operType)
	{
		return operations.at(operType);
	}


private:
	OperationRegistrant() = default;
	OperationRegistrant(const OperationRegistrant&) = delete;
	OperationRegistrant& operator=(const OperationRegistrant) = delete;

	std::map<OperationType, IOperation*> operations;

};