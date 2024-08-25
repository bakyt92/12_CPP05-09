/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:18 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 19:42:05 by ufitzhug         ###   ########.fr       */
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

void    MergeInsertVector( std::vector<std::pair<unsigned int, unsigned int> > &container, const bool &odd, const unsigned int &tmp );
void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, const bool odd, const unsigned int tmp );

template <typename Container>
class PmergeMe {
	private:
		Container	_data;
		value_type	_last;
		double		_time;
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef std::pair <value_type, value_type>	pair_ex;
		typedef	std::vector <pair_ex>;
		PmergeMe(char **input);
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator= (const PmergeMe &rhs);
		int		ft_stoi(char *input);
		void	ft_print_all(void);
};

#endif