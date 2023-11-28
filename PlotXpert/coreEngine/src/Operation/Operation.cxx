#include <Operation.hxx>
#include <stdexcept>

OperationResult* IUnaryOperation::execute(const std::vector<IPointSeries*>& dataSeries)
{
	if (dataSeries.size() != 1) {
		throw std::invalid_argument("UnaryOperation requires exactly one IPointSeries.");
	}

	return unaryExecute(dataSeries[0]);
}



OperationResult* IBinaryOperation::execute(const std::vector<IPointSeries*>& dataSeries)  
{
	if (dataSeries.size() != 2) {
		throw std::invalid_argument("BinaryOperation requires exactly two IPointSeries.");
	}

	return binaryExecute(dataSeries[0], dataSeries[1]);
}

template <class T>
OperationResult* ICustomExtendOperation<T>::execute(const std::vector<IPointSeries*>& dataSeries)
{
	// Call the function. Note: Ensure that the function signature matches the expected usage.
	return m_func(dataSeries);
}