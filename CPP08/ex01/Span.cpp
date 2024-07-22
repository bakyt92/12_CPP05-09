/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:53:31 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/07/22 23:55:15 by ufitzhug         ###   ########.fr       */
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
	this->_list = src._list;
	std::cout << "Copy Span contructor is called." << std::endl;
	*this = src;
}

Span& Span::operator=(const Span &rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		this->_i = rhs._i;
		this->_list = rhs._list;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span destructor is called." << std::endl;
}

class QuantityException : public std::exception {
	public:
		const char* what() const throw() {
        	return "Max size of list is reached. Impossible to add more numbers.";
    }
};

class NotSufficientException : public std::exception {
	public:
		const char* what() const throw() {
        	return "Less than 2 elements. Not possible to find span.";
    }
};

void Span::addNumber(int x)
{
	if (_list.size() >= _i)
		throw QuantityException();
	// std::list<int>::iterator it;
	_list.push_back(x);
	// it = _list.begin();
	// _list.insert(it, x);
	// return ;
}

int Span::shortestSpan()
{
	if (_list.size() < 2)
		throw NotSufficientException();
	std::list<int>::iterator it;
	std::list<int>::iterator it2;
	it = _list.begin();
	it2 = _list.begin();
	++it2;
	int res = std::abs(*it2 - *it);
	while (it2 != _list.end())
	{
		res = std::min(res, std::abs(*it2 - *it));
		++it2;
		++it;
	}
	return res;
}

int Span::longestSpan()
{
	if (_list.size() < 2)
		throw NotSufficientException();
	std::list<int>::iterator it;
	std::list<int>::iterator it2;
	it = _list.begin();
	it2 = _list.begin();
	++it2;
	int res = std::abs(*it2 - *it);
	while (it2 != _list.end())
	{
		res = std::max(res, std::abs(*it2 - *it));
		++it2;
		++it;
	}
	return res;
}