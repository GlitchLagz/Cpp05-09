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

		static void fromInt();
		static void fromChar();
		static void fromFloat();
		static void fromDouble();
		

	public:
		static void convert(std::string src);

};