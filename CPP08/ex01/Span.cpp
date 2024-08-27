/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:53:31 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/27 21:46:06 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int i): _i(i)
{
	std::cout << "Span contructor is called." << std::endl;
}

Span::Span(const Span &src)
{
	this->_i = src._i;
	this->_vec = src._vec;
	std::cout << "Copy Span contructor is called." << std::endl;
	*this = src;
}

Span& Span::operator=(const Span &rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		this->_i = rhs._i;
		this->_vec = rhs._vec;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor is called." << std::endl;
}



void Span::addNumber(int x)
{
	if (_vec.size() >= _i)
		throw QuantityException();
	_vec.push_back(x);
	return;
}

void Span::addPlenty(size_t x)
{
	std::srand(time(0));

	for (size_t i = 0; i < x; i++)
	{
		int random = std::rand() % x;
		_vec.push_back(random);
	}
	return;
}

int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw NotSufficientException();
	std::vector<int>::iterator it;
	std::vector<int>::iterator it2;
	std::sort(_vec.begin(),_vec.end());
	it = _vec.begin();
	it2 = _vec.begin();
	++it2;
	int res = std::abs(*it2 - *it);
	while (it2 != _vec.end())
	{
		res = std::min(res, (*it2 - *it));
		++it2;
		++it;
	}
	return res;
}

int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw NotSufficientException();
	std::sort(_vec.begin(),_vec.end());
	return (*(_vec.end() - 1) - *_vec.begin());
}