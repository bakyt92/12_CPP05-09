/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:27 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/09/15 17:55:33 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char** argv)
{
	if (argc < 2) 
		{
			std::cerr << "Error. No arguments were provided" << std::endl;
			return 1;
		}
	if (argc == 2)
		{
			std::cout << "The line: " << argv[1] << " is sorted" << std::endl;
			return 0;
		}
	
	try {
		PmergeMe<std::vector<int> > instance1(argv + 1);
		PmergeMe<std::deque<int> > instance2(argv + 1);
		instance2.ft_print_all();
		bool    odd = false;
    	int     tmp;
    	if ( (argc - 1) % 2 != 0 ) {
        	odd = true;
        	tmp = std::atoi( argv[argc - 1] );
       		argc-=1;
    	}
		std::vector<std::pair<unsigned int, unsigned int> > vec;
    	for ( int i = 0; i + 1 < argc; i+=2 )
        	vec.push_back( std::make_pair( instance1.get_container_data(i), instance1.get_container_data(i + 1)) );
    	MergeInsertVec( vec, odd, tmp, instance1.get_time1() );
    	std::deque<std::pair<unsigned int, unsigned int> > deq;
    	for ( int i = 0; i + 1 < argc; i+=2 )
        	deq.push_back( std::make_pair( instance2.get_container_data(i), instance2.get_container_data(i + 1)) );
    	MergeInsertDeque( deq, odd, tmp, instance2.get_time1() );
	}
	catch (std::exception &e)
	{
		std::cerr << "Erreur during creation and execution of class. " << std::endl;
		return 1;
	}
	return 0;
}