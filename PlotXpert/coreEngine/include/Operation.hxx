#pragma once

#include <functional>
#include <vector>

#include <OperationResult.hxx>

enum class OperationType
{
	Unary = 0,
	Binary,
	CustomExtend
};

class IPointSeries;

class IOperation {
public:
	virtual ~IOperation() = default;

	virtual OperationType getType() const = 0;
	virtual OperationResult* execute(const std::vector<IPointSeries*>& dataSeries) = 0;
};

class IUnaryOperation : public IOperation {
public:
	OperationResult* execute(const std::vector<IPointSeries*>& dataSeries) override final;

protected:
	virtual OperationResult* unaryExecute(IPointSeries* dataSeries1) = 0;
};

class IBinaryOperation : public IOperation {
public:
	OperationResult* execute(const std::vector<IPointSeries*>& dataSeries) override final;

protected:
	virtual OperationResult* binaryExecute(IPointSeries* dataSeries1, IPointSeries* dataSeries2) = 0;
};

template <class T>
class ICustomExtendOperation : public IOperation {
public:
	OperationResult* execute(const std::vector<IPointSeries*>& dataSeries) override final;

private:
	std::function<T> m_func;
};
