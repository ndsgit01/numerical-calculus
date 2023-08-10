#pragma once

#include <iostream>
#include <functional>

// Refer numerical_differentiation.cpp

double newtons_difference_quotient(std::function<double(double)>,
	double,
	double = 0.00001);

double symmetric_difference_quotient(std::function<double(double)>,
	double,
	double = 0.00001);

double five_point_method(std::function<double(double)>,
	double,
	double = 0.00001);