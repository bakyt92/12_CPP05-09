/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:18 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/09/15 18:00:21 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <sys/time.h>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <utility>

void    MergeInsertVec( std::vector<std::pair<unsigned int, unsigned int> > &container, const bool &odd, const unsigned int &tmp, struct timeval start );
void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, const bool odd, const unsigned int tmp, struct timeval start );

template <typename Container>
class PmergeMe {
	private:
		Container	_data;
		struct timeval start;
		typedef std::pair<unsigned int, unsigned int> pair_ex;
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		
		PmergeMe(char **input);
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator= (const PmergeMe &rhs);
		timeval	get_time1(void);
		int		ft_stoi(char *input);
		void	ft_print_all(void);
		unsigned int get_container_data(int i);
};

template<typename Container>
timeval	PmergeMe<Container>::get_time1(void)
{
	return (this->start);
}

template<typename Container>
int PmergeMe<Container>::ft_stoi(char *input)
{
	std::istringstream ss(input);
	unsigned int num;
	ss >> num;
	return (num);
}

template<typename Container>
void PmergeMe<Container>::ft_print_all(void)
{
	size_t i = 0;
	std::cout << "Before: ";
	while (i < _data.size())
	{
		std::cout << _data[i] << " ";
		i++;
	}
	std::cout << std::endl;
	return;
}

template<typename Container>
unsigned int PmergeMe<Container>::get_container_data(int i)
{
	return(this->_data[i]);
}

template<typename Container>
PmergeMe<Container>::PmergeMe (char **input)
{
	std::cout << "Constructor for instance PmergeMe is called" << std::endl;
	size_t	i = 0;
	while (input[i])
	{
		std::string str_input(input[i]);
		if (str_input.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Wrong symbols in the line" << std::endl;
			return;
		}
		try
		{
			_data.push_back(ft_stoi(input[i]));
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error. Enable to convert input line to integer: " << input[i] << std::endl;
		}
		i++;
	}
	gettimeofday(&start,NULL);
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &src)
{
	std::cout << "Copy constructor is called" << std::endl;
	_data = src._data;
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &rhs) 
{
    if (this != &rhs) {
        _data = rhs._data;
    }
    return *this;
}

template<typename Container>
PmergeMe<Container>::~PmergeMe ()
{
	std::cout << "Destructor for instance PmergeMe is called" << std::endl;
}

#endif