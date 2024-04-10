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