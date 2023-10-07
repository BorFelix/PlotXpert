#pragma once
#include "IOperation.hxx"
#include "IPointSeries.hxx"
#include "OperationResult.hxx"
#include <vector>

class IBinaryOperation : public IOperation {
public:
	virtual void execute(IPointSeries& input1, IPointSeries& input2, OperationResult& result) = 0;
	virtual void execute(const std::vector<IPointSeries*>& input1, const std::vector<IPointSeries*>& input2, OperationResult& result) = 0;
};
