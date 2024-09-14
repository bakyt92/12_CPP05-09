/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:18 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/09/15 00:47:17 by ufitzhug         ###   ########.fr       */
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

// void    MergeInsertVec( std::vector<std::pair<unsigned int, unsigned int> > &container, const bool &odd, const unsigned int &tmp, struct timeval start );
// void    MergeInsertDeque( std::deque<std::pair<unsigned int, unsigned int> > &container, const bool odd, const unsigned int tmp, struct timeval start );

template <typename Container>
class PmergeMe {
	private:
		Container	_data;
		struct timeval start;
		typedef std::pair<unsigned int, unsigned int> pair_ex;
    	// typedef std::vector<pair_ex> PairsV;
    	// PairsV pairsVec;
		// typedef std::deque<pair_ex> PairsD;
    	// PairsD pairsDeq;
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		
		// typedef	std::vector <pair_ex> PairExVec;
		// typedef	std::deque <pair_ex> PairExDeq;
		// PairExDeq PairD;
		// PairExDeq PairV;
		//typedef Container<pair_ex> Pairs;
		PmergeMe(char **input);
		~PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator= (const PmergeMe &rhs);
		timeval	get_time1(void);
		int		ft_stoi(char *input);
		void	ft_print_all(void);
		unsigned int get_container_data(int i);
		// void	pairing(const Container &T);
		// void	sortContainer(void);
		// Container	mergeContainer(Container &T1, Container &T2);
		// Container	fj_sort(Container &T);
		// Container	generate_js (unsigned int x);
		// Container	js_insert(Container &sorted, unsigned int val, unsigned int jacobshtal_pos);
		// Container	mergeInsert (const Container &T1, const Container &T2, const Container &jacob);
};

// typedef std::pair <unsigned int, unsigned int>	pair_ex;
// typedef Container<pair_ex> Pairs;

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

template<>
void PmergeMe<std::vector<unsigned int>>::pairing(const std::vector<unsigned int>& T) {
    for (size_t i = 0; i + 1 < T.size(); i += 2) {
        pairsVec.push_back(std::make_pair(T[i], T[i + 1]));
    }
}

// Specialization for std::deque<unsigned int>
template<>
void PmergeMe<std::deque<unsigned int>>::pairing(const std::deque<unsigned int>& T) {
    for (size_t i = 0; i + 1 < T.size(); i += 2) {
        pairsVec.push_back(std::make_pair(T[i], T[i + 1]));
    }
}



// template<typename Container>
// void	PmergeMe<Container>::pairing(Container T)
// {
// 	if constexpr (std::is_same_v<Container, std::vector<unsigned int>>) {
// 		for (size_t i = 0; i + 1 < T.size(); i += 2)
// 			pairsVec.push_back(std::make_pair(T[i], T[i + 1]));

//     } 
// 	else if constexpr (std::is_same_v<Container, std::deque<unsigned int>>) {
// 		for (size_t i = 0; i + 1 < T.size(); i += 2)
// 			pairsVec.push_back(std::make_pair(T[i], T[i + 1]));
// 	}
// 	return;
// }

template<typename Container>
Container	PmergeMe<Container>::mergeContainer(Container &T1, Container &T2)
{
	Container Res;
	size_t	k = 0;
	size_t	l = 0;
	
	while (k < T1.size() && l < T2.size())
	{
		if (T1[k] > T2[l])
		{
			Res.push_back(T2[l]);
			l++;
		}
		else 
		{
			Res.push_back(T1[k]);
			k++;
		}
	}

	while (k < T1.size())
	{
		Res.push_back(T1[k]);
		k++;
	}
	while (l < T2.size())
	{
		Res.push_back(T2[l]);
		l++;
	}
	return Res;
}
template<typename Container>
Container	PmergeMe<Container>::js_insert(Container &sorted, unsigned int val, unsigned int jacobshtal_pos)
{
	unsigned int low = jacobshtal_pos;
	unsigned int high = sorted.size();
	while (low < high)
	{
		unsigned int mid = low + (high - low) / 2;
		if (sorted[mid] < val)
		{
			low = mid + 1;
		}
		else 
			high = mid;
	}
	sorted.insert(sorted.begin() + low, val);
	return sorted;
}

template<typename Container>
Container	PmergeMe<Container>::mergeInsert (const Container &T1, const Container &T2, const Container &jacob)
{
	Container res = T1;
	for (size_t i = 0; i < T2.size(); ++i)
	{
		int index = std::min(i, jacob.size() - 1);
		res = js_insert(res, T1[i], jacob[index]);
	}
	return res;
}

template<typename Container>
Container	PmergeMe<Container>::fj_sort(Container &T)
{
	if (T.size() < 2)
		return T;
	int mid = T.size() / 2;
	Container left(T.begin(), T.begin() + mid);
	Container right(T.begin() + mid, T.end());

	left = fj_sort(left);
	right = fj_sort(right);

	return (mergeContainer(left, right));
}

template<typename Container>
Container PmergeMe<Container>::generate_js (unsigned int x)
{
	Container jacobshtal_n;
	jacobshtal_n.push_back(0);
	jacobshtal_n.push_back(1);
	unsigned int i = 2;
	while (i <= x)
	{
		jacobshtal_n.push_back(jacobshtal_n[i - 1] + 2 * jacobshtal_n[i - 2]);
		++i;
	}
	return (jacobshtal_n);
}

template<typename Container>
void	PmergeMe<Container>::sortContainer(void)
{
	Container low, high;
	// struct timeval end;
	// long		sec, mic, timeTaken;

	size_t	i = 0;
	if constexpr (std::is_same_v<Container, std::vector<unsigned int>>) {
		while (i < pairsVec.size())
		{
			if (pairsVec[i].first > pairsVec[i].second)
				std::swap(pairsVec[i].first, pairsVec[i].second);
			low.push_back(pairsVec[i].first);
			high.push_back(pairsVec[i].second);
			i++;
		}
	}
	else if constexpr (std::is_same_v<Container, std::deque<unsigned int>>)
	{
		while (i < pairsDeq.size())
		{
			if (pairsDeq[i].first > pairsDeq[i].second)
				std::swap(pairsDeq[i].first, pairsDeq[i].second);
			low.push_back(pairsDeq[i].first);
			high.push_back(pairsDeq[i].second);
			i++;
		}
	}
	low = fj_sort(low);
	Container jacobsthal_num = generate_js(high.size());
	Container sortedContainers = mergeInsert(low, high, jacobsthal_num);
	size_t counter = 0;
	while (counter < sortedContainers.size())
	{
		std::cout << sortedContainers[counter] << " ";
		counter++;
	}
	return;
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
	pairing(_data);
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