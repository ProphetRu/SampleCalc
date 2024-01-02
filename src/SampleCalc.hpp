#pragma once

#include <stdexcept>

template<typename T>
class SampleCalc final
{
public:
	static T Plus(const T& a, const T& b) noexcept
	{
		return a + b;
	}

	static T Minus(const T& a, const T& b) noexcept
	{
		return a - b;
	}

	static T Multiply(const T& a, const T& b) noexcept
	{
		return a * b;
	}

	static T Divide(const T& a, const T& b)
	{
		if (b == 0)
		{
			throw std::invalid_argument("Divisor is zero");
		}

		return a / b;
	}
};
