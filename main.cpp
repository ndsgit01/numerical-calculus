#include <iostream>
#include <numbers>
#include <format>
#include <cmath>

#include "numerical_differentiation.h"
#include "numerical_integration.h"
#include "numerical_ode.h"

/*
* Arc in the first quadrant of the circle centered at origin with radius 2.
*/
double quarter_circle(double x)
{
	return std::sqrt(4 - (x * x));
}

/*
* Represents, y'(x) = f(x, y) = y i.e. df_preimage := f
*/
double df_preimage(double x, double y)
{
	return y;
}

/*
* Observing results of some numerical calculus methods for :
* 1. Differentiation
* 2. Integration
* 3. Ordinary Differential Equation - Initial Value Problem
*/

void observe_differentiation()
{
	std::cout << std::endl;
	std::cout << "Differentiation : log(x) @ 100, Using, " << std::endl;
	std::cout << "Newton's difference quotient: "
		<< newtons_difference_quotient(
			static_cast <double(*)(double)> (std::log),
			100)
		<< std::endl;
	std::cout << "Symmetric difference quotient: "
		<< symmetric_difference_quotient(
			static_cast <double(*)(double)> (std::log),
			100)
		<< std::endl;
	std::cout << "Five point method: "
		<< five_point_method(
			static_cast <double(*)(double)> (std::log),
			100)
		<< std::endl;
	std::cout << std::endl;
}

void observe_integration()
{
	std::cout << std::endl;
	std::cout << "Integration : y = (4-x^2)^0.5 from 0 to 2, which is the area "
		"of a quarter circle of radius 2 and in turn, estimates pi, "
		"Using,"
		<< std::endl;
	std::cout << "Value in C++ std::numbers symbol index: "
		<< std::format("{}", std::numbers::pi)
		<< std::endl;
	auto mpr = mid_point_rule(quarter_circle, 0, 2, 1000001);
	auto tr = trapezoidal_rule(quarter_circle, 0, 2, 1000001);
	auto sr = simpsons_rule(quarter_circle, 0, 2, 1000001);
	std::cout << "Midpoint rule: " << std::format("{}", mpr)
		<< std::endl;
	std::cout << "Trapezoidal rule: "
		<< std::format("{}", tr)
		<< std::endl;
	std::cout << "composite Simpson's 1/3 rule: "
		<< std::format("{}", sr)
		<< std::endl;
	std::cout << std::endl;
}

void observe_ode()
{
	std::cout << std::endl;
	std::cout << "Ordinary differential equations : y' = y such that y(0) = 1, "
		"estimate y(1) which in turn estimates e, Using,"
		<< std::endl;
	std::cout << "Value in C++ std::numbers symbol index: "
		<< std::format("{}", std::numbers::e)
		<< std::endl;
	auto em = euler_method(df_preimage, 0, 1, 1);
	std::cout << "Euler method: "
		<< std::format("{}", em)
		<< std::endl;
	std::cout << std::endl;
}

int main()
{
	observe_differentiation();
	observe_integration();
	observe_ode();

	return 0;
}