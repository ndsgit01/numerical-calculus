#pragma once

#include <iostream>
#include <functional>

// Refer numerical_integration.cpp

double mid_point_rule(std::function<double(double)>,
	double,
	double,
	int = 1001);

double trapezoidal_rule(std::function<double(double)>,
	double,
	double,
	int = 1001);

double simpsons_rule(std::function<double(double)>,
	double,
	double,
	int = 1001);
