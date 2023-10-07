#pragma once
#include <IPointSeries.hxx>
#include <vector>
#include <tuple>

class ThreeDPointSeries : public IPointSeries{
private:
	std::vector<std::tuple<double, double, double>> points;  // Each point is a tuple (x, y, z)
public:
	void addPoint(double x_val, double y_val, double z_val) { points.emplace_back(x_val, y_val, z_val); }
	std::tuple<double, double, double> getPoint(size_t index) const { return points[index]; }
	size_t size() const { return points.size(); }
};
