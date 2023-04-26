#include "rational.h"

#include <cmath>
#include <iostream>

// gcd: returns the greatest common divisor of p and q
// This is done by a variant of Euclid's method
int gcd(int p, int q)
{
	while (q != 0)
	{
		int r = p % q;
		p = q;
		q = r;
	}
	return p;
}
int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}


// Note the use of delegating ctors in the first
// two ctors.
rational::rational()	: rational(0, 1)
{
}

rational::rational(int n) : rational(n, 1)
{
}

// This constructor does all the real work.
rational::rational(int n, int d)	: num(n), den(d)
{
	// Make sure the denominator is positive.
	if (den < 0){
		num = -num;
		den = -den;
	}
	// Reduce to lowest terms.
	auto g = gcd(abs(num), den);
	num = num / g;
	den = den / g;
}

bool operator==(rational lhs, rational rhs)
{
	return (lhs.n() == rhs.n()) && (lhs.d() == rhs.d());
}

bool operator<(rational lhs, rational rhs)
{
	int l, a, b;
	l = lcm(lhs.d(), rhs.d());
	a = lhs.n() * (l / lhs.d());
	b = rhs.n() * (l / rhs.d());
	if (a < b) {
		return true;
	} else {
		return false;
	}

}

bool operator!=(rational lhs, rational rhs)
{
	// Don't touch this code!  It just shows how
	// operator!= can be implmented in terms
	// of operator==.
	return !(lhs == rhs);
}

bool operator>(rational lhs, rational rhs)
{
	// Don't touch this code!  It just shows how
	// operator> can be implmented in terms
	// of operator<.
	return rhs < lhs;
}

bool operator<=(rational lhs, rational rhs)
{
	// Don't touch this code!  It just shows how
	// operator<= can be implmented in terms
	// of operator<.
	return !(rhs < lhs);
}

bool operator>=(rational lhs, rational rhs)
{
	// Don't touch this code!  It just shows how
	// operator>= can be implmented in terms
	// of operator<.
	return !(lhs < rhs);
}

rational operator+(rational lhs, rational rhs)
{
	int l, leftMultiple, rightMultiple;
	l = lcm(lhs.d(), rhs.d());
	leftMultiple = l / lhs.d();
	rightMultiple = l / rhs.d();
	rational sum((leftMultiple * lhs.n()) + (rightMultiple * rhs.n()), l);
	return sum;
}

rational operator-(rational lhs, rational rhs)
{
	int l, leftMultiple, rightMultiple;
	l = lcm(lhs.d(), rhs.d());
	leftMultiple = l / lhs.d();
	rightMultiple = l / rhs.d();
	rational difference((leftMultiple * lhs.n()) - (rightMultiple * rhs.n()), l);
	return difference;
}

rational operator*(rational lhs, rational rhs)
{
	if (lhs.d() == 1) {
		rational product(lhs.n() * rhs.n(), rhs.d());
		return product;
	} else if (rhs.d() == 1) {
		rational product(lhs.n() * rhs.n(), lhs.d());
		return product;
	} else {
		rational product(lhs.n() * rhs.n(), lhs.d() * rhs.d());
		return product;
	}
}

rational operator/(rational lhs, rational rhs)
{
	if (lhs.n() == 1) {
		rational quotient(rhs.d(), lhs.d() * rhs.n());
		return quotient;
	} else if (rhs.n() == 1) {
		rational quotient(lhs.n() * rhs.d(), lhs.d());
		return quotient;
	} else {
		rational quotient(lhs.n() * rhs.n(), lhs.d() * rhs.d());
		return quotient;
	}
}

rational operator-(rational r)
{
	return rational( -r.n(), r.d() );
}
