#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
		{
			return ("Number not found");
		}
};

template<typename T>
typename T::iterator easyfind(T &src, int tofind)
{
	typename T::iterator itr;

	itr = std::find(src.begin(), src.end(), tofind);
	if (itr == src.end())
		throw NotFoundException();
	return itr;
}

