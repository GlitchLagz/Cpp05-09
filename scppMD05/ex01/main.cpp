#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat clonk("clonk", 5);
	std::cout << std::endl;

	try{
		Form donk("donk", 4, 160);
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	try{
		Form zonk("donk", 4, 0);
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	//main test
	try{
		Form bonk("bonk", 4, 10);
		std::cout << bonk;
		clonk.incrementGrade(); // fixes it
		clonk.signForm(bonk);
		std::cout << bonk;
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}