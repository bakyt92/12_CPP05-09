/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:37 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/08 23:14:19 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>

class BitcoinExchange
{
private:
	/* data */
public:
	BitcoinExchange(/* args */);
	~BitcoinExchange();
	void exec_file(std::string line);
};

BitcoinExchange::BitcoinExchange(/* args */)
{
	std::cout << "BitcoinExchange constructor is called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor is called" << std::endl;
}


#endif