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
			std::cout << "Non displayable" << std::endl;
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

void conDouble(const std::string &src)
{
	double cpy = std::atof(src.c_str());
	bool rounder = std::fabs(cpy - static_cast<int>(cpy)) < 0.0000000000001;
	
	std::cout << "char: ";
	if (cpy > 127 || cpy < 0)
		std::cout << "impossible" << std::endl;
	else{
		if (!isprint(cpy))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(cpy) << "'" << std::endl;
	}
	std::cout << "int: ";
	if (cpy < MIN_INT || cpy > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(cpy) << std::endl;
	std::cout << "float: ";
	if (cpy < MIN_FLOAT || cpy > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(cpy) << (rounder ? ".0f" : "f") << std::endl;
	std::cout << "double: ";
	if (cpy < MIN_DOUBLE || cpy > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << cpy << std::endl;
}

void conFloat(const std::string &src)
{
	float cpy = std::atof(src.c_str());
	bool rounder = std::fabs(cpy = static_cast<int>(cpy)) < 0.0000000000001;

	std::cout << "char: ";
	if (cpy > 127 || cpy < 0)
		std::cout << "impossible" << std::endl;
	else{
		if (!isprint(cpy))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(cpy) << "'" << std::endl;
	}
	std::cout << "int: ";
	if (static_cast<long>(cpy) < MIN_INT || static_cast<long>(cpy) > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(cpy) << std::endl;
	std::cout << "float: ";
	if (cpy < MIN_FLOAT || cpy > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << cpy << (rounder ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(cpy) << (rounder ? ".0" : "") << std::endl;
}

void conChar(const std::string &src, int &len)
{
	char cpy = 0;
	if (len == 1)
		cpy = src[0];
	else 
		cpy = src[1];
	std::cout << "char: ";
	if (isprint(cpy))
	{
		std::cout << "'" << cpy << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(cpy) << std::endl;
		std::cout << "float: " << static_cast<float>(cpy) << std::endl;
		std::cout << "double: " << static_cast<double>(cpy) << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

void printOddCase(const std::string &src)
{
	if (src == "nan" || src == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (src == "-inf" || src == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (src == "+inf" || src == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
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
			printOddCase(src);
		default:
			std::cout << "ERR: Invalid input" << std::endl;
			break;
	}
}