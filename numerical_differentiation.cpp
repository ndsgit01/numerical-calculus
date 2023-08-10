#include "numerical_differentiation.h"

/*
*	Given function f and argument x, estimate f'(x).
*
*	Methods implemented:
*	1. Newton's difference quotient
*	2. Symmetric difference quotient
*   3. Five-point method (five-point stencil in 1D)
*/

double newtons_difference_quotient(std::function<double(double)> f,
	double x,
	double step_size /*= 0.0001*/)
{
	return (f(x + step_size) - f(x)) / step_size;
}

double symmetric_difference_quotient(std::function<double(double)> f,
	double x,
	double step_size /*= 0.0001*/)
{
	return (
		f(x + step_size) - f(x - step_size)
		) / (2 * step_size);
}

double five_point_method(std::function<double(double)> f,
	double x,
	double step_size /*= 0.0001*/)
{
	return (
		(-f(x + 2 * step_size)) +
		(8 * f(x + step_size)) -
		(8 * f(x - step_size)) +
		(f(x - 2 * step_size))
		) / (12 * step_size);
}