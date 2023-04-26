
#include <cassert>
#include <iostream>
#include <string>

#include "rational.h"

int main(int argc, char * argv[])
{
	int tests = -1;
	if (argc > 1)
		tests = atoi(argv[1]);

	// Test ctors and accessors.
	if (tests & 1)
	{
		std::cout << "Testing ctors and accessors\n";
		rational r1;
		assert(r1.n() == 0);
		assert(r1.d() == 1);

		rational r2{ 5 };
		assert(r2.n() == 5);
		assert(r2.d() == 1);

		rational r3{ 3, 5 };
		assert(r3.n() == 3);
		assert(r3.d() == 5);

		rational r4{ 8, 12 };
		assert(r4.n() == 2);
		assert(r4.d() == 3);
	}

	rational n1d3{ 1, 3 };
	rational n1d4{ 1, 4 };

	// Test equality operators.
	if (tests & 2)
	{
		std::cout << "Testing equality operators\n";
		assert(n1d3 == rational( 1, 3 ));
		assert(n1d4 == rational( 1, 4 ));
		assert(n1d3 != n1d4);
		assert(n1d4 != n1d3);
	}

	if (tests & 4)
	{
		std::cout << "Testing comparison operators\n";
		assert(n1d4 < n1d3);
		assert(n1d4 <= n1d3);
		assert(n1d4 <= n1d4);
		assert(n1d3 > n1d4);
		assert(n1d3 >= n1d4);
		assert(n1d3 >= n1d3);
	}

	// Test addition and subtraction.
	if (tests & 8)
	{
		std::cout << "Testing addition and subtraction\n";
		rational n7d12(7, 12);
		rational n7d3{ 7, 3 };
		rational n1d12{ 1, 12 };
		rational mn1d12{ -n1d12 };
		rational n1d2{ 1, 2 };

		assert(n1d3 + n1d4 == n7d12);
		assert(n1d4 + n1d3 == n7d12);
		assert(n1d3 + 2 == n7d3);
		assert(2 + n1d3 == n7d3);
		assert(n1d3 - n1d4 == n1d12);
		assert(n1d4 - n1d3 == mn1d12);
		assert(n1d4 + n1d4 == n1d2);
	}

	// Test multiplication and division.
	if (tests & 16)
	{
		std::cout << "Testing multiplication and division\n";
		rational n1d12{ 1, 12 };
		rational n1d9{ 1, 9 };
		rational n1d16{ 1, 16 };
		rational n4d3{ 4, 3 };
		rational n3d4{ 3, 4 };

		assert(n1d3 * n1d4 == n1d12);
		assert(n1d4 * n1d3 == n1d12);
		assert(n1d3 * n1d3 == n1d9);
		assert(n1d4 * n1d4 == n1d16);
		assert(n1d3 / n1d4 == n4d3);
		assert(n1d4 / n1d3 == n3d4);
		assert(n1d3 / n1d3 == 1);
		assert(n1d4 / n1d4 == 1);
		assert(1 / n4d3 == n3d4);
		assert(1 / n3d4 == n4d3);
	}
	return 0;
}
