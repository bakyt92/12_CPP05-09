/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:34 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/15 22:00:27 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool validate_date(std::string date)
{
	size_t delim1 = date.find('-');
	int year = std::stoi(date.substr(0, delim1));
	if (year < 2009 || year > 2022 || delim1 == std::string::npos)
	{
		std::cerr << "Error. Wrong year" << std::endl;
		return (1);
	}
	date.erase(0, delim1);
	size_t delim1 = date.find('-');
	int month = std::stoi(date.substr(0, delim1));
	if (month < 1 || month > 12 || delim1 == std::string::npos)
	{
		std::cerr << "Error. Wrong month" << std::endl;
		return (1);
	}
	date.erase(0, delim1);
	int day = std::stoi(date);
	int day_q[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (day > 31)
	{
		std::cerr << "Error. Wrong month" << std::endl;
		return (1);
	}
	return(0);
}

void validate_value(std::string value)
{

}


bool BitcoinExchange::read_db(std::string data1)
{
	std::fstream db_data(data1, std::fstream::in);
	if (db_data.is_open())
	{
		std::cout << "Database is opened successfully" << std::endl;
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
		return 1;
	}
	return 0;
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
		std::cout << "File of input is opened successfully" << std::endl;
		std::string line;
		std::getline(file1, line);
		while (std::getline(file1, line))
		{
			size_t delim = line.find('|');
			if  (delim == std::string::npos || (delim + 2) < line.size())
				std::cerr << "Error. Wrong data " << "in line: " << line << std::endl;
			std::string date = line.substr(0, delim);
			std::string val = line.substr(delim + 1);
			validate_date(date);
			validate_value(val);
		}
	}
	else
	{
		std::cerr << "Error with opening file" << std::endl;
	}
}
