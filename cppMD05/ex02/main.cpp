#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{
	Bureaucrat clonk("clonk", 137);
	Bureaucrat donk("donk", 45);
	Bureaucrat zonk("zonk", 5);
	std::cout << std::endl;

	try{
		{
			ShrubberyCreationForm form("Shrub");
			clonk.signForm(form);
			std::cout << form;
			clonk.executeForm(form);
		}
		{
			RobotomyRequestForm form("Rob the Robot");
			donk.signForm(form);
			std::cout << form;
			donk.executeForm(form);
		}
		{
			PresidentialPardonForm form("Epstein");
			zonk.signForm(form);
			std::cout << form;
			zonk.executeForm(form);
		}
	}
	catch(std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}