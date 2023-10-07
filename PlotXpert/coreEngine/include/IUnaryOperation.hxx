#pragma once
#include "IOperation.hxx"
#include "IPointSeries.hxx"
#include "OperationResult.hxx"
#include <vector>

class IUnaryOperation : public IOperation {
public:
	virtual void execute(IPointSeries& input, OperationResult& result) = 0;
	virtual void execute(const std::vector<IPointSeries*>& input, OperationResult& result) = 0;
};
