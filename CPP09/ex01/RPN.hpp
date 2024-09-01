/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:02 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/09/01 21:43:06 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPH_HPP
#define RPH_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <climits>
#include <limits.h>
#include <stdlib.h>
#include <exception>

std::string ft_ctos(char *input);
int ft_stoi(std::string input);

class RPN
{
private:
	std::string line;
	std::stack<int> digits;
	int res;
public:
	RPN(char* input);
	~RPN();
	RPN(const RPN &src);
	RPN& operator=(const RPN &rhs);
	bool ft_execute(char c);
	bool ft_readline(std::string input_line);
	bool ft_validation(std::string input_line);
};

#endif