/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 20:44:39 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	MergeInsertVec(std::vector<std::pair<unsigned int, unsigned int> >&container, const bool &odd,const unsigned int &tmp)
{
	std::vector <unsigned int> low, high;
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
	std::cout << "Time to sort a range of " << high.size() << " elements with std::vector: " << timeTaken << " microseconds" << std::endl;
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
        for ( int i = 0; i < 6; i++ )
            std::cout << high[i] << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;

    gettimeofday( &end, NULL );
    sec = end.tv_sec - start.tv_sec;
    mic = end.tv_usec - start.tv_usec;
    timeTaken = ( sec / 1000000 ) + ( mic );
    std::cout << "Time to sort a range of " << high.size() << " elements with std::deque : " << timeTaken << " microseconds" << std::endl;
}