#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class	AForm;
class	Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _tar;
		ShrubberyCreationForm();
	
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		std::string getTarget() const;

		void execute(Bureaucrat const &executor)const;
};

//std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *src);

#endif