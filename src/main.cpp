#include <iostream>
#include <string>
#include "SampleCalc.hpp"

int main(int argc, char* argv[]) noexcept
{
	if (argc != 4)
	{
		std::cerr << "[!] Usage: " << argv[0] << " <int a> <op + - * /> <int b>\n";
		return 0;
	}

	try
	{
		auto a = std::stoi(argv[1]);
		auto b = std::stoi(argv[3]);

		switch (argv[2][0])
		{
		case '+':
			std::cout << a << argv[2] << b << "=" << SampleCalc<int>::Plus(a, b) << std::endl;
			break;
		case '-':
			std::cout << a << argv[2] << b << "=" << SampleCalc<int>::Minus(a, b) << std::endl;
			break;
		case '*':
			std::cout << a << argv[2] << b << "=" << SampleCalc<int>::Multiply(a, b) << std::endl;
			break;
		case '/':
			std::cout << a << argv[2] << b << "=" << SampleCalc<int>::Divide(a, b) << std::endl;
			break;
		default:
			throw std::invalid_argument("Invalid operation");
		}
	}
	catch (const std::invalid_argument& ex)
	{
		std::cerr << "[!] Error: " << ex.what() << std::endl;
	}
	catch (const std::out_of_range& ex)
	{
		std::cerr << "[!] Error: " << ex.what() << std::endl;
	}

	return 0;
}
