#include "ScalarConverter.hpp"

static int isOddCase(const std::string src)
{
	if (src == "nan" || src == "nanf" || src == "+inf" || src == "+inff" || src == "-inf" || src == "-inff")
		return 1;
	return 0;
}

static int isChar(const std::string src, int len)
{
	
}
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