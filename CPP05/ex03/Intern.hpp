/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:54:47 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 20:01:14 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{

public:
	Intern();
	AForm& makeForm(std::string name_form, std::string target);
	Intern(Intern& src);
	Intern& operator=(Intern &rhs);
	~Intern();
};

#endif