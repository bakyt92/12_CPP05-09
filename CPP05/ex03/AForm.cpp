/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:26 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 18:56:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm (std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_isSigned = false;
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "AForm constructor is called." << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm copy constructor is called." << std::endl;
    *this = src;
}

AForm& AForm::operator= (const AForm &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

int AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getIsSigned() const
{
    return (this->_isSigned);
}

void AForm::beSigned(const Bureaucrat &rhs)
{
    if (rhs.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else 
        throw (Bureaucrat::GradeTooLowException());
}

void AForm::toExecute(const Bureaucrat &rhs) const
{
    if (_isSigned == false)
        throw (AForm::FormNotSignedException());
    else 
        {
            if (this->getGradeToExecute() < rhs.getGrade())
                throw (Bureaucrat::GradeTooLowException());
        }
    return;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}

std::ostream& operator<< (std::ostream &output, const AForm &src)
{
	output << "AForm is named " << src.getName() << " with grade to sign: " << src.getGradeToSign() 
        << " and grade to execute: " << src.getGradeToExecute() << std::endl;
	return output;
}

AForm::~AForm()
{
    std::cout << "AForm destructor is called." << std::endl;
}

