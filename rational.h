//
//	rational
//
//	rational.h and rational.cpp implement a marginally
//	useful class for modelling rational numbers.  This
//	is NOT production ready; it will not handle the
//	large fractions that arise in common usage.

//	For pedagogical purposes, this code is over-
//	commented.

#pragma once

class rational
{
public:
	// The default constructor initializes the value to zero.
	// The one that takes an integer argument provides
	// a rational with that integer value. 
	// The 2-argument constructor simply assigns the 
	// numerator and denominator to the given values.
	rational();
	rational(int n);
	rational(int n, int d);

	// accessors to return private data
	int n() { return num; }
	int d() { return den; }

private:

	// A rational number is simply a numerator and a denominator,
	// with the properties:
	//	  (1) den != 0
	//	  (2) gcd(num,den) == 1
	int num;
	int den;
};

// The API for rational is sufficiently complete that we
// can write all these standard operators as non-member
// functions.

// Logical operators
//
// Note that we only really need to implement
// operator== and operator<.  The rest can be
// synthesized from those.
bool operator==(rational lhs, rational rhs);
bool operator!=(rational lhs, rational rhs);
bool operator<(rational lhs, rational rhs);
bool operator>(rational lhs, rational rhs);
bool operator<=(rational lhs, rational rhs);
bool operator>=(rational lhs, rational rhs);

// Arithmetic operators
rational operator+(rational lhs, rational rhs);
rational operator-(rational lhs, rational rhs);
rational operator*(rational lhs, rational rhs);
rational operator/(rational lhs, rational rhs);
rational operator-(rational r);
