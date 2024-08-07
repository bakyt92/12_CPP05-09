/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:43:29 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/08 22:26:47 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "Number of arguments is not correct. Please enter only 2 agrs (name of program and input string)" << std::endl;
	}
	else
	{
		ScalarConverter::Convert(argv[1]);
	}
	return 0;
}