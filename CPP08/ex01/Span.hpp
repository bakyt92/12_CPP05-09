/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:53:35 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/07/22 18:56:48 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN
#define SPAN

#include <iostream>
#include <algorithm>
#include <list>
#include <exception>

class Span
{
private:
	std::list<int> _list;
	unsigned int _i;
public:
	Span(unsigned int i);
	Span(const Span &src);
	Span& operator=(const Span &rhs);
	~Span();

	void addnumber(int x);
	int shortestSpan();
	int longestSpan();
};

#endif