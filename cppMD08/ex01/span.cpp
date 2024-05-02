#include "Span.hpp"

Span::Span(): _N(0)
{}

Span::Span(unsigned int N): _N(N)
{}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
        _N = src._N;
    return (*this);
}

Span::Span(const Span &src)
{
    operator=(src);
}

Span::~Span()
{}

void Span::addNumber(int n)
{

}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{

}

unsigned int Span::shortestSpan() const
{

}

unsigned int Span::longestSpan() const
{

}

const char *Span::SpanContainerFullException::what() const throw()
{
    return ("ERR: Span Container Is Full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return ("ERR: Not Enough Numbers In Container");
}