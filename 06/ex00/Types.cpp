#include "ScalarConverter.hpp"

static int isOddCase(const std::string &src)
{
	if (src == "nan" || src == "nanf" || src == "+inf" || src == "+inff" || src == "-inf" || src == "-inff")
		return 1;
	return 0;
}

static int isChar(const std::string &src, int &len)
{
	if ((len == 1 && !isdigit(src[0])) || (len == 3 && src[0] == '\'' && src[2] == '\''))
		return 1;
	return 0;
}

static int isInt(const std::string &src, int &len)
{
	int i = 0;
	bool flag = false;

	if (src[0] == '-' || src[0] == '+')
	{
		flag = 1;
		i++;
	}
	while ((src[i] && len > 0 && len < 12) || (src[i] && !flag && len > 0 && len < 11))
		if (!isdigit(src[i++]))
			return 0;
	return 1;
}

static int isFloat(const std::string &src, int &len, int &dot_char)
{
	for (int i = dot_char - 1; i > -1; i--)
		if (!isdigit(src[i]))
			if ((i != 0) || (i == 0 && src[i] != '+' && src[i] != '-'))
				return 0;
	for (int i = dot_char + 1; i < len; i++)
		if ((!isdigit(src[i]) && src[i] != 'f') || (src[i] == 'f' && (i != len - 1)))
			return 0;
	return 1;
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