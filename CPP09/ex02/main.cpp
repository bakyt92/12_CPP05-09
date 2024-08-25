/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:27 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 16:03:48 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char** argv)
{
	if (argc < 2) 
		std::cerr << "Error. No arguments were provided" << std::endl;
	try {
		PmergeMe<std::vector<int> > instance1(argv);
		PmergeMe<std::deque<int> > instance2(argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	
	
}