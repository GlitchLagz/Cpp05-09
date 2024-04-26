#pragma once
#include <iostream>
#include <exception>

template<typename T>
typename T::iterator easyfind(T &src, int tofind)
{
	typename T::iterator itr;
}
class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
		{
			return ("Number not found");
		}
};

