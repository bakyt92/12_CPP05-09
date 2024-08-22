/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/22 21:38:58 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(char* input)
{
	std::cout << "RPN constructor is called" << std::endl;
	this->line = ft_ctos(input);
	ft_readline(this->line);
}

RPN::~RPN()
{
	std::cout << "RPN destructor is called" << std::endl;
}

void RPN::ft_readline(std::string input_line)
{
	
}