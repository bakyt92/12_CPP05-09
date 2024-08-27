/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:53:35 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/27 21:37:09 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN
#define SPAN

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span
{
private:
	std::vector<int> _vec;
	unsigned int _i;
public:
	Span(unsigned int i);
	Span(const Span &src);
	Span& operator=(const Span &rhs);
	~Span();

	void addNumber(int x);
	void addPlenty(size_t x);
	int shortestSpan();
	int longestSpan();
};

class QuantityException : public std::exception {
	public:
		const char* what() const throw() {
        	return "Max size of vector is reached. Impossible to add more numbers.";
    }
};

class NotSufficientException : public std::exception {
	public:
		const char* what() const throw() {
        	return "Less than 2 elements. Not possible to find span.";
    }
};

#endif