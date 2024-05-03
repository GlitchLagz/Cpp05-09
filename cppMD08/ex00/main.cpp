#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>


int main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> dq;

	for(int i = 0; i < 15; i++)
		vec.push_back(i);
	try{
		std::cout << *easyfind(vec, 7) << std::endl;
		std::cout << *easyfind(vec, 16) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	for(int i = 0; i < 15; i++)
		lst.push_back(i);
	try{
		std::cout << *easyfind(lst, 14) << std::endl;
		std::cout << *easyfind(lst, 16) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	for(int i = 0; i < 15; i++)
		dq.push_back(i);
	try{
		std::cout << *easyfind(dq, 0) << std::endl;
		std::cout << *easyfind(dq, 16) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}