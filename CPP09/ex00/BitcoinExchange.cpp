/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:34 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/12 22:46:59 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::read_db(std::string data1)
{
	std::fstream db_data(data1, std::fstream::in);
	if (db_data.is_open())
	{
		std::cout << "File is opened successfully" << std::endl;
		std::string line;
		size_t divider;
		std::getline(db_data, line);
		while (std::getline(db_data, line))
		{
			divider = line.find(',');
			std::string rate = line.substr(divider + 1);
			this->btc_db[line.substr(0, divider)] = std::stof(rate);
		}
		db_data.close();
	}
	else
	{
		std::cerr << "Error with opening file" << std::endl;
	}

	return;
}

BitcoinExchange::BitcoinExchange(std::string input): address(input)
{
	std::cout << "BitcoinExchange constructor is called" << std::endl;
	exec(address);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor is called" << std::endl;
}

void BitcoinExchange::exec(std::string address)
{
	if (read_db(DATABASE) == false)
	{
		std::cerr << "Error with opening Database" << std::endl;
		return;
	}
	std::fstream file1(address, std::fstream::in);
	if (file1.is_open())
	{
		std::cout << "File is opened successfully" << std::endl;

	}
	else
	{
		std::cerr << "Error with opening file" << std::endl;
	}
}
