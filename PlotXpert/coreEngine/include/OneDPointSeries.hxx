#pragma once
#include <IPointSeries.hxx>
#include <vector>

class OneDPointSeries : public IPointSeries {
private:
	double x;

public:
	std::vector<Point> getPoints() const override;
};