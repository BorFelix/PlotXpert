#pragma once
#include <IPointSeries.hxx>
#include <tuple>
#include <vector>

template<typename... T>
class CustomPointSeries : public IPointSeries {
private:
	std::vector<std::tuple<T...>> points; // Using tuple to represent custom points
public:
	std::vector<Point> getPoints() const override;
};
