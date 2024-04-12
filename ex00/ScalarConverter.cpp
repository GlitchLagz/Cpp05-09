#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	return ;
}
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	operator=(src);
}
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}
ScalarConverter::ScalarConverter()
{
	return ;
}

void conInt(const std::string &src)
{
	long cpy = std::atol(src.c_str());
	
	std::cout << "char: ";
	if (cpy > 127 || cpy < 0)
		std::cout << "impossible" << std::endl;
	else{
		if (!isprint(cpy))
			std::cout << "ERR: Cant display this char" << std::endl;
		else
			std::cout << "'" << static_cast<char>(cpy) << "'" << std::endl;
	}
	std::cout << "int: ";
	if (cpy < MIN_INT || cpy > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(cpy) << std::endl;
	std::cout << "float: " << static_cast<float>(cpy) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(cpy) << ".0" << std::endl;
}

void ScalarConverter::convert(std::string src)
{
	int len = src.length();
	int type = getType(src, len);

	switch(type)
	{
		case INT:
			conInt(src);
			break;
		case DUB:
			conDouble(src);
			break;
		case FLO:
			conFloat(src);
			break;
		case CHR:
			conChar(src, len);
			break;
		case SPE:
			printSpecial(src);
		default:
			std::cout << "ERR: Invalid input" << std::endl;
			break;
	}
}