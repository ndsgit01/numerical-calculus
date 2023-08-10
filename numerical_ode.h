#pragma once

#include <iostream>
#include <functional>

// Refer numerical_ode.cpp

double euler_method(std::function<double(double, double)>,
	double, double,
	double,
	int = 1000000);
