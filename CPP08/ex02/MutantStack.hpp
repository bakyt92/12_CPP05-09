/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:47:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/06 22:49:09 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <exception>
#include <stack>

template <typename T>

class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack(void);
	MutantStack(const MutantStack &src);
	MutantStack &operator=(const MutantStack &rhs);
	~MutantStack(void);

	iterator begin(void);
	iterator end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void) {
	std::cout << "Constructor of class MutantStack is called" << std::endl;
};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src) {
	std::cout << "Copy constructor of class MutantStack is called" << std::endl;
	*this = src;
};

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &rhs) {
	std::cout << "Copy operator MutantStack is called" << std::endl;
	std::stack<T>::operator=(rhs);
	return *this;
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
};

template<typename T>
MutantStack<T>::~MutantStack(void) {
	std::cout << "Destructor of class MutantStack is called" << std::endl;
};

#endif