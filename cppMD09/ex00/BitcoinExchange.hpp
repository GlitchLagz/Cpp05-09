#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <exception>

class Btc
{
    private:
        int flag;
        std::map <std::string, float> data;
    
    public:
        Btc();
        Btc(Btc const &src);
        Btc& operator=(Btc const &src);
        ~Btc();

        void setData(std::string date, float nb);
        std::map<std::string, float> getData();

        void readFile(std::string path);
        std::vector<std::string> cpp_split(std::string src, char dl);

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