#pragma once

#include <iostream>
#include <tuple>
#include <vector>

// IPointSeries.h
class IPointSeries {
public:
	virtual ~IPointSeries() = default;
};

class OneDPointSeries : public IPointSeries
{
private:
	std::vector<double> m_points;

public:
	explicit OneDPointSeries(const std::vector<double>& points): m_points(points){};

	double getNthPoint(int idx) const
	{
		try
		{
			m_points.at(idx);
		}
		catch (const std::out_of_range& e)
		{
			std::cout << e.what() << '\n';
		}
	};
};

class TwoDPointSeries : public IPointSeries
{
private:
	std::vector<std::pair<double, double>> m_points;

public:
	explicit TwoDPointSeries(const std::vector<std::pair<double, double>>& points) : m_points(points) {};

	std::pair<double, double> getNthPoint(int idx) const
	{
		try
		{
			m_points.at(idx);
		}
		catch (const std::out_of_range & e)
		{
			std::cout << e.what() << '\n';
		}
	};
};

class ThreeDPointSeries : public IPointSeries
{
private:
	std::vector<std::tuple<double, double, double>> m_points;

public:
	explicit ThreeDPointSeries(const std::vector<std::tuple<double, double, double>>& points) : m_points(points) {};

	std::tuple<double, double, double> getNthPoint(int idx) const
	{
		try
		{
			m_points.at(idx);
		}
		catch (const std::out_of_range & e)
		{
			std::cout << e.what() << '\n';
		}
	};
};

template <class PointType>
class CustomPointSeries : public IPointSeries
{
private:
	std::vector<PointType> m_points;

public:
	explicit CustomPointSeries(const std::vector<PointType>& points) : m_points(points) {};

	PointType getNthPoint(int idx) const
	{
		try
		{
			m_points.at(idx);
		}
		catch (const std::out_of_range & e)
		{
			std::cout << e.what() << '\n';
		}
	};
};
