#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main (void)
{
	Bureaucrat clonk("clonk", 1);
	Intern	intern;
	AForm *form;
	AForm *form2;
	AForm *form3;
	AForm *form4;
	std::cout << std::endl;

	try{
		form = intern.makeForm("ShrubberyCreationForm", "Shrub");
		std::cout << *form;
		clonk.signForm(*form);
		clonk.executeForm(*form);
		std::cout << std::endl;
		form2 = intern.makeForm("RobotomyRequestForm", "Rob");
		std::cout << *form2;
		clonk.signForm(*form2);
		clonk.executeForm(*form2);
		std::cout << std::endl;
		form3 = intern.makeForm("PresidentialPardonForm", "Epstein");
		std::cout << *form3;
		clonk.signForm(*form3);
		clonk.executeForm(*form3);
		std::cout << std::endl;
		form4 = intern.makeForm("Non-existant Form", "untargetable target");
		std::cout << *form4;
		clonk.signForm(*form4);
		clonk.executeForm(*form4);
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	delete form;
	delete form2;
	delete form3;
	delete form4;
	return 0;
}