#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructed" << std::endl;
}

Intern& Intern::operator=(const Intern &src)
{
	if (this == &src)
		return *this;
	return *this;
}

Intern::Intern(const Intern &src)
{
	operator=(src);
}

Intern::~Intern()
{
	std::cout << "Intern Destructed" << std::endl;
}

static AForm *makeShrub(const std::string tar)
{
	return (new ShrubberyCreationForm(tar));
}

static AForm *makeRobot(const std::string tar)
{
	return (new RobotomyRequestForm(tar));
}

static AForm *makePres(const std::string tar)
{
	return (new PresidentialPardonForm(tar));
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Intern cant find the requested form, try something else";
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
	AForm *(*form_lst[])(const std::string) = {&makeShrub, &makeRobot, &makePres};
	std::string form_strs[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form == form_strs[i])
		{
			std::cout << "Intern Creates " << form << std::endl;
			return (form_lst[i](target));
		}
	}
	throw FormNotFoundException();
	return (NULL);
}