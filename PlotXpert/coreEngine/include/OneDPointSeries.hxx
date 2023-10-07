#pragma once
#include <IPointSeries.hxx>
#include <vector>

class OneDPointSeries : public IPointSeries{
private:
	std::vector<double> x_values;
public:
	void addX(double x_val) { x_values.push_back(x_val); }
	double getX(size_t index) const { return x_values[index]; }
	size_t size() const { return x_values.size(); }
};
