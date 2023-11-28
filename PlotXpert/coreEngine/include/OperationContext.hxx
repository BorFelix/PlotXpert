#pragma once

#include <vector>

#include <Operation.hxx>

class IOperationContext
{
public:
	virtual ~IOperationContext() = default;	//If a derived class object is deleted through a pointer to a base class that has a non-virtual destructor, the destructor of the derived class does not get called.

	virtual OperationType getOperationType() const = 0;
	virtual std::vector<IPointSeries*> getData() const = 0;
};


class UnaryOperationContext : public IOperationContext
{
public:
	UnaryOperationContext(OperationType type, IPointSeries* data);

	OperationType getOperationType() const override;
	std::vector<IPointSeries*> getData() const override;

private:
	OperationType m_operationType;
	std::vector<IPointSeries*> m_data;
};


class BinaryOperationContext : public IOperationContext
{
public:
	BinaryOperationContext(OperationType type, IPointSeries* data1, IPointSeries* data2);

	OperationType getOperationType() const override;
	std::vector<IPointSeries*> getData() const override;

private:
	OperationType m_operationType;
	std::vector<IPointSeries*> m_data;
};


class CustomExtendOperationContext : public IOperationContext
{
public:
	CustomExtendOperationContext(OperationType type, std::vector<IPointSeries*> data);

	OperationType getOperationType() const override;
	std::vector<IPointSeries*> getData() const override;

private:
	OperationType m_operationType;
	std::vector<IPointSeries*> m_data;
};


