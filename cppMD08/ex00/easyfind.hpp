#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &src, int tofind)
{
	typename T::iterator itr;

	itr = std::find(src.begin(), src.end(), n);
	if (itr == src.end())
		throw NotFoundExeception();
	return itr;
}
class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
		{
			return ("Number not found");
		}
};

