#include "numerical_integration.h"

/*
*	Given function f and limits a and b, estimate integral which gives area
*	under f from a to b.
*
*	Methods implemented:
*	1. Midpoint rule
*	2. Trapezoidal rule
*	3. composite Simpson's 1/3 rule
*/

double mid_point_rule(std::function<double(double)> f,
	double a,
	double b,
	int intervals /*= 1001*/)
{
	auto interval_size = (b - a) / intervals;
	auto riemann_sum = 0.0;
	for (auto i = 0; i < intervals; i++)
	{
		riemann_sum += f((a + interval_size / 2) +
			i * interval_size);
	}
	riemann_sum *= interval_size;
	return riemann_sum;
}

double trapezoidal_rule(std::function<double(double)> f,
	double a,
	double b,
	int intervals /*= 1001*/)
{
	auto interval_size = (b - a) / intervals;
	auto trapezoidal_sum = 0.0;
	for (auto i = 1; i < intervals; i++)
	{
		trapezoidal_sum += f(a + i * interval_size);
	}
	trapezoidal_sum += (f(a) + f(b)) / 2;
	trapezoidal_sum *= interval_size;
	return trapezoidal_sum;
}

double simpsons_rule(std::function<double(double)> f,
	double a,
	double b,
	int intervals /*= 1001*/)
{
	if (intervals % 2 == 0)
	{
		intervals += 1;
	}
	auto interval_size = (b - a) / intervals;
	auto simpsons_sum = 0.0;
	for (auto i = 1; i < intervals; i++)
	{
		if (i % 2 == 0)
		{
			simpsons_sum += 4 * f(a + i * interval_size);
		}
		else {
			simpsons_sum += 2 * f(a + i * interval_size);
		}
	}
	simpsons_sum += (f(a) + f(b));
	simpsons_sum *= (interval_size / 3);
	return simpsons_sum;
}