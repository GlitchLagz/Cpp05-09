#pragma once
# include <iostream>
# include <string>
# include <limits>
# include <cstdlib>
# include <cctype>
# include <cmath>

# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define INV -1
# define INT 0
# define DUB 1
# define FLO 2
# define CHR 3
# define SPE 4


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();

	public:
		static void convert(std::string src);

};
	void conInt(const std::string &src);
	void conChar(const std::string &src, int &len);
	void conFloat(const std::string &src);
	void conDouble(const std::string &src);
	void printOddCase(const std::string &src);
	int getType(const std::string &src, int &len);