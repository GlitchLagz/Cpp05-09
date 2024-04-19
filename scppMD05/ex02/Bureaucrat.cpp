#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("unnamed"), _grade(150)
{
	std::cout << "Bureaucrat " << this->getName() << " Constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		std::cout << "Bureaucrat " << this->getName() << " Constructed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return *this;
	_grade = src._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	operator=(src);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->getName() << " Destructed" << std::endl;
}

std::string const Bureaucrat::getName() const
{
	return this->_name;
}

int const Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}
//
void Bureaucrat::signForm(AForm &src)
{
	src.beSigned(*this);
}

void Bureaucrat::incrementGrade(void)
{
	try{
		std::cout << "Attempting to increment " << this->getName() << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << "Failed to increment " << this->getName() << ": " << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void)
{
	try{
		std::cout << "Attempting to decrement " << this->getName() << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << "Failed to decrement " << this->getName() << ": " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception &e){
		std::cout << _name << " cannot execute " << form.getName() << " because: "
			<< e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat& bureaucrat)
{
	o << bureaucrat.getName() << " has a grade of " << bureaucrat.getGrade() << std::endl;
	return o;
}