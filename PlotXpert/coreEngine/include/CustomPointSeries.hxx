#pragma once
#include <IPointSeries.hxx>
#include <tuple>
#include <vector>

template<typename... T>
class CustomPointSeries : public IPointSeries {
private:
	std::vector<std::tuple<T...>> points; // Using tuple to represent custom points
public:
	void addPoint(const std::tuple<T...>& point) { points.push_back(point); }
	const std::tuple<T...>& getPoint(size_t index) const { return points[index]; }
	size_t size() const { return points.size(); }
};
