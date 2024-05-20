/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:55:54 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/20 18:01:39 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base () 
{
	std::cout << "Base constructor is called" << std::endl;
}

Base::~Base () 
{
	std::cout << "Base destructor is called" << std::endl;
}