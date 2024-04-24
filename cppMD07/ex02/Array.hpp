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
        Array(Array const &cpy);
        Array &operator=(Array const &cpy);
        ~Array();

        T &operator[](unsigned int i);
        T const &operator[](unsigned int i) const;

        unsigned int size() const;
};