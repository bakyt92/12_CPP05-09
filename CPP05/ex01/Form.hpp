/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/08 18:01:02 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;
class Form
{
private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    Form();
public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    ~Form();
    Form(const Form &src);
    Form& operator= (const Form &rhs);
    int getGradeToSign() const; 
    int getGradeToExecute() const;
    std::string getName() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat &rhs);
    
    class GradeTooHighException : public std::exception {
		public:
			virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char * what() const throw();
	};
};

std::ostream& operator<< (std::ostream &os, const Form &src);

#endif