#include <OperationResult.hxx>
#include <PointSeries.hxx>

OperationResult::OperationResult(IPointSeries* resultPoints, bool isSuccess, std::string message) 
	: m_resultPoints(resultPoints), m_isSuccess(isSuccess), m_message(message)
{

}

// Implement getters, setters, and other utility methods
