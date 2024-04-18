#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "ERR: enter a single argument of the following: Char, Int, Float, Double" << std::endl;
	return 0;
}