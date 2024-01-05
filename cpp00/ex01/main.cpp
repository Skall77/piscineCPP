/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:56:28 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:01 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <ios>

int main(void)
{
	PhoneBook P;
	bool infinite = true;
	std::string choice;

	P.welcome();

	while(infinite)
	{
		std::cout << '>';
		if (!std::getline(std::cin, choice))
			return (1);
		if (choice == "ADD")
			P.add();
		if (choice == "SEARCH")
			P.search();
		if (choice == "EXIT")
		{
			std::cout << "Thanks for using the not so good Phonebook !" << std::endl;
			infinite = false;
		}
	}
	return (0);
}