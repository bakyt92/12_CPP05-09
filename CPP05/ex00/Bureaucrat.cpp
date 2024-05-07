/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:43 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/07 19:44:58 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy constructor is called." << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != & rhs)
	{
		// this->_name = rhs._name;
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
	if (this->getGrade() > 150)
		throw GradeTooLowException();
	else if (this->getGrade() < 1)
		throw GradeTooLowException();
	this->_grade--;
	std::cout << this->getName() << " has been upgraded by 1 lvl" << std::endl;
	return;
	/*
	if (this->getGrade() <= 150 && this->getGrade() >= 1)
		{
			this->_grade--;
			std::cout << this->getName() << " has been upgraded by 1 lvl" << std::endl;
		}
	if (this->getGrade() > 150)
		throw GradeTooLowException();
	else if (this->getGrade() < 1)
		throw GradeTooLowException();
		*/
	return;
}

void Bureaucrat::downGrade(void)
{
	if (this->getGrade() > 150)
		throw GradeTooLowException();
	else if (this->getGrade() < 1)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << this->getName() << " has been downgraded by 1 lvl" << std::endl;
	/*
	if (this->getGrade() <= 150 && this->getGrade() >= 1)
		{
			this->_grade++;
			std::cout << this->getName() << " has been downgraded by 1 lvl" << std::endl;
		}
	if (this->getGrade() > 150)
		throw GradeTooLowException();
	else if (this->getGrade() < 1)
		throw GradeTooLowException();
		*/
	return;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
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