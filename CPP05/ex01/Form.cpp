/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:53 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/08 14:52:46 by ufitzhug         ###   ########.fr       */
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

int Form::getGradeToExecute()
{
    return (this->_gradeToExecute);
}

int Form::getGradeToSign()
{
    return (this->_gradeToSign);
}

std::string Form::getName()
{
    return (this->_name);
}

void Form::beSigned(const Bureaucrat &rhs)
{
    if (rhs.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
        
}

std::ostream& operator<< (std::ostream &os, const Form &src)
{
	os << "Form is named " << src.getName() << " with grade: " << src.getGrade();
	return os;
}

Form::~Form()
{
    std::cout << "Form destructor is called." << std::endl;
}

