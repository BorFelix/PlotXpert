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
	Unary = 0,
	Binary,
	CustomExtend
};

class OperationResult {};  // Placeholder for OperationResult class.

class IOperation {
public:
	virtual ~IOperation() = default;
	virtual OperationResult execute(const IPointSeries& data) = 0;
};

class IUnaryOperation : public IOperation {
public:
	OperationResult execute(const IPointSeries& data) override;
};

class IBinaryOperation : public IOperation {
public:
	OperationResult execute(const IPointSeries& data1, const IPointSeries& data2);
};


template<typename... T>
class ICustomExtendOperation : public IOperation {
public:
	OperationResult execute(const std::vector<CustomPointSeries<T...>*>& data, OperationResult& result) = 0;
};
