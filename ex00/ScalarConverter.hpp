#pragma once
# include <iostream>
# include <string>

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