/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:47:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/05 23:46:09 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
#define MUTANTSTACK

#include <iostream>
#include <algorithm>
#include <list>
#include <exception>
#include <stack>

template <typename T>

class MutantStack : public std::stack {
public:
	MutantStack(void);
	MutantStack(const MutantStack &src);
	MutantStack &operator=(const MutantStack &rhs);
	~MutantStack(void);

	iterator start(void);
	iterator end(void);
		
}

#endif