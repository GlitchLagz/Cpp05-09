#include "ScalarConverter.hpp"

int getType(std::string &src, int &len)
{
	int f_char = src.find('f'), dot_char = src.find('.');

	if (dot_char == std::string::npos)
	{
		if (isOddCase(src))
			return SPE;
		if (isChar(src, len))
			return CHR;
		if (isInt(src, len))
			return INT;
	}
	if (f_char != std::string::npos && dot_char != std::string::npos)
		if (isFloat(src, len, dot_char))
			return FLO;
	else if (f_char == std::string::npos && dot_char != std::string::npos)
		return DUB;
	return INV;
}