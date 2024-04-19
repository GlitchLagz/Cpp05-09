#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern &src);
		Intern& operator=(const Intern &src);
		~Intern();

		AForm *makeForm(const std::string form, const std::string target);

		class FormNotFoundException: public std::exception {
			virtual const char* what() const throw();
		};
};