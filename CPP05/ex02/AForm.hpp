/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:24 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/09 18:29:57 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    AForm();
public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    ~AForm();
    AForm(const AForm &src);
    AForm& operator= (const AForm &rhs);
    int getGradeToSign() const; 
    int getGradeToExecute() const;
    std::string getName() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat &rhs);
    virtual void execute(const Bureaucrat &executor) { } = 0; 
    
    class GradeTooHighException : public std::exception {
		public:
			virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char * what() const throw();
	};
};

std::ostream& operator<< (std::ostream &os, const AForm &src);

#endif