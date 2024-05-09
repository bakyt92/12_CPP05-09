/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/09 20:41:11 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat Premiere("First_b", 11);
	// Bureaucrat Deuxieme("Second_b", 0);
	// Bureaucrat Troisieme("Third_b", 155);
	try {
		Bureaucrat Deuxieme("Second_b", 0);
	// 	Bureaucrat Troisieme("Third_b", 155);
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
	// try
	// {
	// 	AForm formz("Billet Paris", 10, 8);
	// 	Premiere.signForm(formz);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	return 0;
}