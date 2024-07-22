/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:53:31 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/07/22 18:58:55 by ufitzhug         ###   ########.fr       */
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

