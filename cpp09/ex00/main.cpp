/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:04:25 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:04:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

float stringToFloat(const std::string& s);

int main(int argc, char** argv) 
{

	std::string line;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	std::ifstream input(argv[1], std::ifstream::in);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	std::ifstream data("./data.csv", std::ifstream::in);
	if (!data.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	
	BitCoinExchange btc(data);

	std::getline(input, line);
	while(std::getline(input, line))
	{
		if (line.find('|') == std::string::npos 
			|| line.length() < line.find('|') + 2)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, line.find('|') - 1);
		std::string eRate = line.substr(line.find('|') + 2);
		if (!btc.checkDateFormat(date)
			|| !btc.checkValidDate(date))
			continue;
		if (!btc.checkExchangeRate(eRate))
			continue;
		
		std::cout << date << " => " << stringToFloat(eRate) << " = ";
		std::cout << stringToFloat(eRate) * btc.getExchangeRate(date) << std::endl;
	}
	input.close();
	data.close();
	return(0);
}