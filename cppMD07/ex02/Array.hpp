#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array{
    private:
        T *_arr;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const &src);
        Array &operator=(Array const &src);
        ~Array();

        T& operator[](unsigned int i);
        T const &operator[](unsigned int i) const;

        unsigned int size() const;

        class OutOfRangeException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};