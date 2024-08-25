/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 19:26:20 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename Container>
int PmergeMe<Container>::ft_stoi(char *input)
{
	std::istringstream ss(input);
	int num;
	ss >> num;
	return (num);
}

template<typename Container>
void PmergeMe<Container>::ft_print_all(void) 
{
	size_t i = 0;
	while (i < _data.size())
	{
		std::cout << _data[i] << " _";
	}
	std::cout << std::endl;
}


template<typename Container>
PmergeMe<Container>::PmergeMe (char **input)
{
	std::cout << "Constructor for instance PmergeMe is called" << std::endl;
	_time = 0;
	_last = -1;
	size_t	i = 0;
	while (input[i])
	{
		std::string str_input(input[i])
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
}


template<typename Container>
PmergeMe<Container>::~PmergeMe ()
{
	std::cout << "Destructor for instance PmergeMe is called" << std::endl;
}

void	MergeInsertVec(std::vector<std::pair<int, int>>&container, const bool &odd,const int &tmp)
{
	std::vector <int> low, high;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	long		sec, mic, timeTaken;

	size_t	i = 0;
	while (i < container.size())
	{
		if (container[i].first > container[i].second)
			std::swap(container[i].first, container[i].second);
		i++;
	}
	i = 0;
	while (i < container.size())
	{
		low.push_back(container[i].first);
		high.push_back(container[i].second);
		i++;
	}
	std::sort(high.begin(), high.end());
	i = 0;
	while (i < low.size())
	{
		high.insert(std::lower_bound(high.begin(), high.end(), low[i]), low[i]);
		i++;
	}
	if (odd)
	{
		high.insert(std::lower_bound(high.begin(), high.end(), tmp), tmp);
	}

	std::cout << "After: ";
	if ( high.size() < 6 ) {
        for ( size_t i = 0; i < high.size(); i++ )
            std::cout << high[i] << " ";
    } else {
        for ( int i = 1; i < 6; i++ )
            std::cout << high[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;
	gettimeofday(&end, NULL);
	sec = end.tv_sec - start.tv_sec;
	mic = end.tv_usec - start.tv_usec;
	timeTaken = (sec / 1000000) + mic;
	std::cout << "Time to sort a range of " << high.size() << " elements with std::vector: " << timeTaken << std::endl;
}

void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, const bool odd, const unsigned int tmp ) {
    std::deque<unsigned int>   low, high;
    struct timeval  start, end;
    long            sec, mic, timeTaken;

    gettimeofday( &start, NULL );
	size_t i = 0;
	while (i < container.size())
	{
		if ( container[i].first > container[i].second )
            std::swap( container[i].first, container[i].second );
		i++;
	}
	i = 0;
	while (i < container.size())
	{
		low.push_back( container[i].first );
		high.push_back( container[i].second );
		i++;
	}
    std::sort( high.begin(), high.end() );
    for ( size_t i = 0; i < low.size(); i++ )
        high.insert( std::lower_bound( high.begin(), high.end(), low[i]), low[i] );

    if ( odd )
        high.insert( std::lower_bound( high.begin(), high.end(), tmp), tmp );

    std::cout << "After  : ";
    if ( high.size() < 6 ) {
        for ( size_t i = 0; i < high.size(); i++ )
            std::cout << high[i] << " ";
    } else {
        for ( int i = 1; i < 6; i++ )
            std::cout << high[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;

    gettimeofday( &end, NULL );
    sec = end.tv_sec - start.tv_sec;
    mic = end.tv_usec - start.tv_usec;
    timeTaken = ( sec / 1000000 ) + ( mic );
    std::cout << "Time to process a range of " << high.size() << " elements with std::deque : " << timeTaken << " microseconds" << std::endl;
}