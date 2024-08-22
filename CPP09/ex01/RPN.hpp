/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:02 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/22 21:39:09 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPH_HPP
#define RPH_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::string ft_ctos(char *input)
{
	std::stringstream ss;
	ss<< input;
	std::string s1 = ss.str();
	return s1;
}

class RPN
{
private:
	std::string line;
	std::stack<float> st1;
	std::stack<char> ops;
public:
	RPN(char* input);
	~RPN();

	void ft_readline(std::string input_line);
};

#endif