/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 18:07:13 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat Premiere("First_b", 11);
	// Bureaucrat Deuxieme("Second_b", 0);
	// Bureaucrat Troisieme("Third_b", 155);
	try {
		Bureaucrat Deuxieme("Second_b", 0);
	 	Bureaucrat Troisieme("Third_b", 155);
		ShrubberyCreationForm form1 ("Melanin");
		
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// Bureaucrat Deuxieme("Second_b", 0);
	try {
		Premiere.upGrade();
		Premiere.upGrade();
		Premiere.upGrade();
		// Deuxieme.upGrade();
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}