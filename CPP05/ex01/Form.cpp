/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:53 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/08 17:10:22 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form (std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_isSigned = false;
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (_gradeToExecute < 1 || _gradeToSign > 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Form constructor is called." << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form copy constructor is called." << std::endl;
    *this = src;
}

Form& Form::operator= (const Form &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}

int Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getIsSigned() const
{
    return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat &rhs)
{
    if (rhs.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else 
        throw (GradeTooLowException());
}

std::ostream& operator<< (std::ostream &output, const Form &src)
{
	output << "Form is named " << src.getName() << " with grade to sign: " << src.getGradeToSign() 
        << " and grade to execute: " << src.getGradeToExecute() << std::endl;
	return output;
}

Form::~Form()
{
    std::cout << "Form destructor is called." << std::endl;
}

