#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Enter an argument of the following: Char, Int, Float, Double" << std::endl;
	return 0;
}