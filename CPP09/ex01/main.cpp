/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:48 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/22 21:14:53 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error. Wrong quantity of args" << std::endl;
		return 0;
	}
	RPN instance1(argv[1]);
	return 0;
}