#include "numerical_ode.h"

/*
*	Given a function dy, i.e. y' = f(x, y) and initial value defined by
*	(x_0, y_0) i.e. y(x_0) = y_0, and an argument x, estimate y(x).
*
*	Methods implemented:
*	Euler method (forward euler method)
*/

double euler_method(std::function<double(double, double)> dy,
	double x_0, double y_0,
	double x,
	int steps /*= 100000*/)
{
	int direction = (x - x_0) > 0 ? 1 : -1;
	auto step_size = (x - x_0) / steps;
	auto x_i = x_0;
	auto y_i = y_0;
	while (direction * (x_i - x) < 0)
	{
		y_i += (step_size * dy(x_i, y_i));
		x_i += step_size;
	}
	return y_i;
}