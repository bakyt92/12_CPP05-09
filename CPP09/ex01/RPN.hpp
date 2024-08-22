/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:02 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/23 00:08:43 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPH_HPP
#define RPH_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::string ft_ctos(char *input);
int ft_stoi(std::string input);

class RPN
{
private:
	std::string line;
	std::stack<int> digits;
	std::stack<char> ops;
public:
	RPN(char* input);
	~RPN();
	
	bool RPN::ft_readline(std::string input_line);
};

#endif