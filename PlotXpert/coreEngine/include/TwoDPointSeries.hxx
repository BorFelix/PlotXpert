#pragma once
#include <IPointSeries.hxx>
#include <vector>
#include <utility> // for std::pair

class TwoDPointSeries : public IPointSeries{
private:
	std::vector<std::pair<double, double>> points;  // Each point is a pair (x, y)
public:
	void addPoint(double x_val, double y_val) { points.emplace_back(x_val, y_val); }
	std::pair<double, double> getPoint(size_t index) const { return points[index]; }
	size_t size() const { return points.size(); }
};
