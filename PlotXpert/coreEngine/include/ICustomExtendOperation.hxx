#pragma once
#include "IOperation.hxx"
#include "OperationResult.hxx"
#include "CustomPointSeries.hxx"
#include <vector>

template<typename... T>
class ICustomExtendOperation : public IOperation {
public:
	virtual void execute(const std::vector<CustomPointSeries<T...>*>& data, OperationResult& result) = 0;
};
