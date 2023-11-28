#pragma once
#include <string>

class IPointSeries;

class OperationResult {
private:
	IPointSeries* m_resultPoints;
	bool m_isSuccess;
	std::string m_message;
public:
	OperationResult() = default;

	OperationResult(IPointSeries* resultPoints, bool isSuccess, std::string message);
	
	// Getters, setters, and other utility methods
};
