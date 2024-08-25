/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:27 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 17:25:49 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char** argv)
{
	if (argc < 2) 
		std::cerr << "Error. No arguments were provided" << std::endl;
	try {
		PmergeMe<std::vector<int> > instance1(argv + 1);
		PmergeMe<std::deque<int> > instance2(argv + 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	
}