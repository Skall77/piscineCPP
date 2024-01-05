/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:44:54 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/30 09:44:54 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_COIN_EXCHANGE_HPP
#define BIT_COIN_EXCHANGE_HPP

#include <map>
#include <iostream>

class BitCoinExchange
{
	public:

		BitCoinExchange();
		BitCoinExchange(std::ifstream& db);
		BitCoinExchange(const BitCoinExchange& copy);
		BitCoinExchange& operator=(const BitCoinExchange& obj);

		~BitCoinExchange();

		float	getExchangeRate(const std::string& date);
		bool	checkDateFormat(const std::string& date);
		bool	checkValidDate(const std::string& date);
		bool	checkExchangeRate(const std::string& eRate);


	private:
		std::map<std::string, float> _DB;

		void MakeDB(std::ifstream& db);
};

#endif