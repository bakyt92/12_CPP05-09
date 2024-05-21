/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:47:23 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/21 17:48:29 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T* _data;
	int _size;
public:
	Array() : _data(new T), _size(0) {
		std::cout << "Constructor: Array created with size of " << this->_size << std::endl;
	}
	
	Array(unsigned int n): _data(new T[n]), _size(n)  {
		std::cout << "Constructor: Array created with size of " << this->_size << std::endl;
	}
	
	Array(const & src): _data(new T[src._size]), _size(src._size)
	{
		std::cout << "Copy constructor for class Array is called" << std::endl;
		int i = 0;
		while (i < this->_size)
		{
			src._data[i] = this->data;
			i++;
		}
	}

	Array& operator=(Array &rhs const)
	{
		std::cout << "Copy assignment operator for class Array is called" << std::endl;
		if (rhs != this)
		{
			this->_size = rhs._size;
			int i = 0;
			while (i < this->_size)
			{
				src._data[i] = this->data;
				i++;
			}
		}
		return *this;
	}
	
	~Array() {
		delete [] _data;
	};
};

#endif