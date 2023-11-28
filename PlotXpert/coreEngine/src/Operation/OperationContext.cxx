#include <OperationContext.hxx>

UnaryOperationContext::UnaryOperationContext(OperationType type, IPointSeries* data)
	: m_operationType(type)
{
	m_data[0] = data;
}

OperationType UnaryOperationContext::getOperationType() const {
	return m_operationType;
}

std::vector<IPointSeries*> UnaryOperationContext::getData() const {
	return m_data;
}


BinaryOperationContext::BinaryOperationContext(OperationType type, IPointSeries* data1, IPointSeries* data2)
	: m_operationType(type) {
	m_data[0] = data1;
	m_data[1] = data2;
}

OperationType BinaryOperationContext::getOperationType() const {
	return m_operationType;
}

std::vector<IPointSeries*> BinaryOperationContext::getData() const {
	// Return the first data series; adjust as needed for your logic
	return m_data;
}

CustomExtendOperationContext::CustomExtendOperationContext(OperationType type, std::vector<IPointSeries*> data)
	: m_operationType(type), m_data(data) {}

OperationType CustomExtendOperationContext::getOperationType() const {
	return m_operationType;
}

std::vector<IPointSeries*> CustomExtendOperationContext::getData() const {
	// Return the first data series; adjust as needed for your logic
	return m_data;
}