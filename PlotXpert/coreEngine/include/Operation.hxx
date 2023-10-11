#pragma once

#include <vector>

#include "IPointSeries.hxx"
#include "OperationResult.hxx"
#include "OneDPointSeries.hxx"
#include "TwoDPointSeries.hxx"
#include "ThreeDPointSeries.hxx"
#include "CustomPointSeries.hxx"

enum class OperationType
{
	//Unary Operation
	//Binary Operation
	//Custom Operation
};

class IOperation {
public:
	virtual ~IOperation() = default;
	virtual OperationType getType() const = 0;
};


class IUnaryOperation : public IOperation {
public:
	virtual void execute(IPointSeries& input, OperationResult& result) = 0;
	virtual void execute(const std::vector<IPointSeries*>& input, OperationResult& result) = 0;
};


class IBinaryOperation : public IOperation {
public:
	virtual void execute(IPointSeries& input1, IPointSeries& input2, OperationResult& result) = 0;
	virtual void execute(const std::vector<IPointSeries*>& input1, const std::vector<IPointSeries*>& input2, OperationResult& result) = 0;
};


template<typename... T>
class ICustomExtendOperation : public IOperation {
public:
	virtual void execute(const std::vector<CustomPointSeries<T...>*>& data, OperationResult& result) = 0;
};