#include "Span.hpp"

Span::Span(): _N(0)
{}

Span::Span(unsigned int N): _N(N)
{}

Span &Span::operator=(const Span &src)
{
    if (this != &src){
        _N = src._N;
        _v = src._v;
    }
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
    if (_v.size() >= _N)
        throw SpanContainerFullException();
    _v.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_v.size() + std::distance(begin, end) > _N)
        throw NotEnoughNumbersException();
    _v.insert(_v.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
    std::vector<int> tmp = _v;

    if (_v.size() <= 1)
        throw NotEnoughNumbersException();
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++)
        if (tmp[i] - tmp[i-1] < min)
            min = tmp[i] - tmp[i-1];
    return min;
}

unsigned int Span::longestSpan() const
{
    std::vector<int> tmp = _v;

    if (_v.size() <= 1)
        throw NotEnoughNumbersException();
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::SpanContainerFullException::what() const throw()
{
    return ("ERR: Span Container Is Full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return ("ERR: Not Enough Numbers In Container");
}