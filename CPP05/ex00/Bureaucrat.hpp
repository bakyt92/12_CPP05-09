/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:47 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/07 17:16:34 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat & operator= (const Bureaucrat &rhs);
	const std::string getName() const;
	void setGrade(int g);
	int getGrade() const;
	~Bureaucrat();
};

#endif