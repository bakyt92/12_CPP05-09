/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/07 19:44:35 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Premiere("First_b", 2);
	Bureaucrat Deuxieme("Second_b", 0);
	Bureaucrat Troisieme("Third_b", 155);
	// try {
	// 	Bureaucrat Deuxieme("Second_b", 0);
	// 	Bureaucrat Troisieme("Third_b", 155);
	// }
	// catch (const std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	try {
		Premiere.upGrade();
		Premiere.upGrade();
		Premiere.upGrade();
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}