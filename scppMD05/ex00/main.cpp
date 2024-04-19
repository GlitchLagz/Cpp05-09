#include "Bureaucrat.hpp"

int main (void)
{
	try{
		Bureaucrat ape("ape", 1);
		std::cout << ape;
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	try{
		Bureaucrat cat("cat", 150);
		std::cout << cat;
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	try{
		Bureaucrat dog("dog", 0);
		std::cout << dog;
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	try{
		Bureaucrat donk("donk", 151);
		std::cout << donk;
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;std::cout << std::endl;

	// increment
	try{
		Bureaucrat clonk("clonk", 3);
		std::cout << clonk;
		clonk.incrementGrade();
		std::cout << clonk;
		clonk.incrementGrade();
		std::cout << clonk;
		clonk.incrementGrade(); // breaks it
		std::cout << clonk;
		
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;std::cout << std::endl;

	// decrement
	try{
		Bureaucrat bonk("bonk", 148);
		std::cout << bonk;
		bonk.decrementGrade();
		std::cout << bonk;
		bonk.decrementGrade();
		std::cout << bonk;
		bonk.decrementGrade(); // breaks it
		std::cout << bonk;
		
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}