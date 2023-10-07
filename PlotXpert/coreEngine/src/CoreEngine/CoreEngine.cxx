#include <CoreEngine.hxx>

void CoreEngine::execute(IUnaryOperation& operation, IPointSeries& input, OperationResult& result) {
	operation.execute(input, result);  // Mock execution for unary operation
}

void CoreEngine::execute(IBinaryOperation& operation, IPointSeries& input1, IPointSeries& input2, OperationResult& result) {
	operation.execute(input1, input2, result);  // Mock execution for binary operation
}

void CoreEngine::execute(IUnaryOperation& operation, const std::vector<IPointSeries*>& input, OperationResult& result) {
	operation.execute(input, result);  // Mock execution for unary operation with vector
}

void CoreEngine::execute(IBinaryOperation& operation, const std::vector<IPointSeries*>& input1, const std::vector<IPointSeries*>& input2, OperationResult& result) {
	operation.execute(input1, input2, result);  // Mock execution for binary operation with vectors
}

template<typename... T>
void CoreEngine::execute(ICustomExtendOperation<T...>& operation, const std::vector<CustomPointSeries<T...>*>& data, OperationResult& result) {
	operation.execute(data, result);  // Mock execution for custom operations
}
