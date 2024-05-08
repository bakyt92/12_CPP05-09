/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:43 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/08 17:09:04 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{ 
	std::cout << "Bureaucrat constructor is called." << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else 
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Bureaucrat copy constructor is called." << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != & rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGrade(int g)
{
	this->_grade = g;
	return;
}

void Bureaucrat::upGrade(void)
{
	this->_grade--;
	std::cout << this->getName() << " has been upgraded by 1 lvl" << std::endl;
	if (this->getGrade() > 150)
		throw GradeTooLowException();
	else if (this->getGrade() < 1)
		throw GradeTooHighException();
	return;
}

void Bureaucrat::downGrade(void)
{
	this->_grade++;
	std::cout << this->getName() << " has been downgraded by 1 lvl" << std::endl;
	if (this->getGrade() > 150)
		throw GradeTooLowException();
	else if (this->getGrade() < 1)
		throw GradeTooHighException();
	return;
}

/* -- New function -- */

void Bureaucrat::signForm(Form &src)
{
	try
	{
		src.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << " signed a form "  << src.getName() << std::endl; 
		
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat " << this->getName() << " could not sign a form " 
		 << src.getName() << " because " << e.what() << std::endl;
	}
}
/* -- New function OLD -- */

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade of Bureaucrat is too low.";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade of Bureaucrat is too high.";
}

std::ostream& operator<< (std::ostream &os, const Bureaucrat &src)
{
	os << "Bureaucrat is named " << src.getName() << " with grade: " << src.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat()
{ 
	std::cout << "Bureaucrat destructor is called." << std::endl;
}