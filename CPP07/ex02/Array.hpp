/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:47:23 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/21 19:14:38 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <time.h>

class OffLimitsException : public std::exception
{
	public:
		virtual const char* what() const throw() {
        	return "Data in pointer is out of limits";
    }			
};

template <typename T>
class Array
{
private:
	T* _data;
	int _size;
public:
	Array<T>() : _data(new T), _size(0) {
		std::cout << "Constructor: Array created with size of " << this->_size << std::endl;
	}
	
	Array<T>(unsigned int n): _data(new T[n]), _size(n)  {
		std::cout << "Constructor: Array created with size of " << this->_size << std::endl;
	}
	
	Array<T>(const Array<T> & src): _data(new T[src._size]), _size(src._size)
	{
		std::cout << "Copy constructor for class Array is called" << std::endl;
		int i = 0;
		while (i < this->_size)
		{
			this->_data[i] = src._data[i];
			i++;
		}
	}

	Array<T>& operator=(const Array<T> &rhs)
	{
		std::cout << "Copy assignment operator for class Array is called" << std::endl;
		if (&rhs != this)
		{
			delete [] _data;
			this->_size = rhs._size;
			this->_data = new T[this->_size];
			int i = 0;
			while (i < this->_size)
			{
				this->_data[i] = rhs._data[i];
				std::cout << "From data " << rhs._data[i] << " copy to this->data " << this->_data[i] << std::endl;
				i++;
			}
		}
		return *this;
	}
	
	int size(void) {
		return (this->_size);
	}

	T& operator[](int i) const {
		if (i < 0 || i > this->_size)
			throw OffLimitsException();
		return this->_data[i];
	}

	~Array() {
		delete [] _data;
	};
};

#endif