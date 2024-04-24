#include "iter.hpp"

void decrement(int const &n)
{
	std::cout << n - 1 << std::endl;
}

void print(std::string const &n)
{
	std::cout << n << std::endl;
}

void to_lower(std::string &src)
{
    for(int i = 0; i < src.length(); i++)
        src[i] = std::tolower(src[i]);
}

int main(void)
{
    int array[] = {4, 2, 6, 2};
	std::string strings[] = {"ABC", "123", "HELLO WORLD!"};
	std::cout << std::endl;
	::iter(strings, 3, print);
    ::iter(strings, 3, to_lower);
    std::cout << std::endl;
    ::iter(strings, 3, print);
    std::cout << std::endl;
	::iter(array, 4, decrement);
	std::cout << std::endl;

    return 0;
}