#pragma once
#include<math.h>

// Define a tolerance value for floating-point comparisons. 
// This is to account for small discrepancies in floating-point arithmetic.
#define TOLERANCE 0.0000001

// A static function that checks the equality of two double values with respect to a tolerance.
// The use of fabs computes the absolute difference between the two numbers.
// If this difference is less than the defined tolerance, the numbers are considered equal.
static bool IsEqualD(double a, double b)
{
	return fabs(a - b) < TOLERANCE;
}