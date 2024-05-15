#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

class Btc
{
    private:
    	std::map <std::string, float> data;
    	int flag;
    public:
    	Btc();
    	~Btc();
    	Btc& operator=(Btc const &var);
    	Btc(Btc const &var);

    	void setData(std::string date, float value);

    	void readFile(std::string path);

    	std::map<std::string, float> getData();
    	std::vector<std::string> cpp_split(std::string str, char dl);
        class ParseValueException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NotANumberException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};