#pragma once
# include <iostream>
# include <string>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
};