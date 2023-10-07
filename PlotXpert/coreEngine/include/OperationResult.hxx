#pragma once
#include <string>

class IPointSeries;

class OperationResult {
private:
	IPointSeries* resultPoints;
	bool isSuccess;
	std::string message;
public:
	OperationResult();
	// Getters, setters, and other utility methods
};
