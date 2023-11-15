#pragma once
#include <IPointSeries.hxx>
#include <vector>
#include <tuple>

class ThreeDPointSeries : public IPointSeries {
private:
	double x, y, z;

public:
	std::vector<Point> getPoints() const override;
};
