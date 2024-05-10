/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:54:53 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 21:31:05 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor is called" << std::endl;
}

Intern& Intern::operator=(Intern &rhs)
{
	
	std::cout << "Copy assignment operator for Intern is called";
	if (this != & rhs)
		return *this;
	else 
		return *this;
}

Intern::Intern(Intern& src)
{
	std::cout << "Intern copy constructor is called." << std::endl;
	*this = src;
}


Intern::~Intern()
{
	std::cout << "Intern destructor is called" << std::endl;
}

AForm& Intern::makeForm(std::string name_form, std::string target)
{
	AForm* form1;
	try
	{
		if (target.length() < 1)
			throw NoTargetException();
		switch (name_form[0])
	{
	case 'S':
		form1 = new ShrubberyCreationForm(target);
		break;
	case 'P':
		form1 = new PresidentialPardonForm(target);
		break;
	case 'R':
		form1 = new RobotomyRequestForm(target);
		break;
	default:
		form1 = NULL;
		throw NotCorrectNameException();
		// std::cout << "Intern can't create a form named " << name_form << std::endl;
		break;
	}
	}
	catch(const std::exception& e)
	{
		std::cout << "Intern can't create a form named " << name_form << " because of " << e.what() << std::endl;
	}
	return (*form1);
}

const char* Intern::NotCorrectNameException::what() const throw()
{
	return "Name form is not correct. It should begin with (R) for Robotomy, (S) for Shrubbery, (P) for Presidential pardon.";
}

const char* Intern::NoTargetException::what() const throw()
{
	return "Target is not declared";
}