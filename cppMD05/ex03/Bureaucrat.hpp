#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class  Bureaucrat 
{
	private:
		const	std::string _name;
		int		_grade;
		void setGrade(int grade);
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat& operator=(Bureaucrat const &src);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		std::string const getName() const;
		int const getGrade() const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm &src);
		void executeForm(const AForm &form) const;

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat& bureaucrat);

#endif