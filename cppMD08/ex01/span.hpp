#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _v;

    public:
        Span();
        Span(unsigned int N);
        Span &operator=(const Span &src);
        Span(const Span &src);
        ~Span();

        void addNumber(int n);
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class SpanContainerFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};