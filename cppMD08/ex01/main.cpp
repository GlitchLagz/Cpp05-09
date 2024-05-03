#include "Span.hpp"
#include <cstdlib>

int main(void)
{
	//pdf tests//
    Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	//errs
	try{
		sp.addNumber(12);
	}
	catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	Span sp_2 = Span(5);
	try{
		sp_2.addNumber(12);
		sp_2.shortestSpan();
	}
	catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		sp_2.longestSpan();
	}
	catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	//addrange tests//
	Span sp_3 = Span(100);
	std::vector<int> v;
	std::srand(time(NULL));
	for (int i = 0; i < 100; i++)
		v.push_back(rand() % 10000);
	try{
		sp_3.addRange(v.begin(), v.end());
		std::cout << "shortest span: " << sp_3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp_3.longestSpan() << std::endl;
	}
	catch (std::exception const &e){
		std::cout << e.what() << std::endl;
	}
    return 0;
}