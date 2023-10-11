#pragma once
#include <vector>
#include <string>
#include <Operation.hxx>
#include <IPointSeries.hxx>
#include <OperationResult.hxx>

class CoreEngine {
public:
	void execute(IUnaryOperation& operation, IPointSeries& input, OperationResult& result);
	void execute(IBinaryOperation& operation, IPointSeries& input1, IPointSeries& input2, OperationResult& result);
	void execute(IUnaryOperation& operation, const std::vector<IPointSeries*>& input, OperationResult& result);
	void execute(IBinaryOperation& operation, const std::vector<IPointSeries*>& input1, const std::vector<IPointSeries*>& input2, OperationResult& result);


	template<typename... T>
	void execute(ICustomExtendOperation<T...>& operation, const std::vector<CustomPointSeries<T...>*>& data, OperationResult& result);
};
