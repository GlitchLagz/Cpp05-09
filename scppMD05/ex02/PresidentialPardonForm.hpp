#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	AForm;
class	Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		const std::string _tar;
		PresidentialPardonForm();
	
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		std::string getTarget() const;

		void execute(Bureaucrat const &executor)const;
};

#endif