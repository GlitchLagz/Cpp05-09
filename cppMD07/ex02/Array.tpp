#pragma once

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{}

template <typename T>
Array<T>::Array(const Array &src) : _arr(new T[src._size]), _size(src._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = src._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
    if (this != &src)
    {
        delete[] _arr;
        _size = src._size;
        _arr = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = src._arr[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete [] _arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfRangeException();
    return _arr[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OutOfRangeException();
    return _arr[i];
}

template <typename T>
unsigned int Array<T>::size() const{
    return _size;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw(){
    return ("Index is out of range");
}