/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:12:41 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/27 16:03:44 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_nb_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::welcome(void) const
{
	std::cout << "Welcome to the not so good Phonebook :" << std::endl;
	std::cout << "--- Type ADD to add a new contact ---" << std::endl;
	std::cout << "- Type SEARCH to look for a contact -" << std::endl;
	std::cout << "-------- Type EXIT to leave ---------" << std::endl;
}

void PhoneBook::add(void)
{
	if (this->_nb_contacts > 7)
	{
		this->_contacts[this->_nb_contacts % 8].set_all(_nb_contacts % 8);
		this->_nb_contacts++;
		std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
	}
	else
	{
		this->_contacts[this->_nb_contacts].set_all(_nb_contacts);
		this->_nb_contacts++;
		std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
	}	
}

bool PhoneBook::if_numbers(std::string& str) const
{
    for (char const &c : str) 
	{
        if (std::isdigit(c) == 0)
          return false;
	}
	return (true);
}

void PhoneBook::search(void) const
{
	int temp;
	
	if (this->_nb_contacts == 0)
		std::cout << "ADD contact before SEARCH for them" << std::endl;
	else
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		if (this->_nb_contacts > 7)
			temp = 8;
		else
			temp = this->_nb_contacts;
		for (int i = 0; i < temp; i++)
			this->_contacts[i].display_search();
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << std::endl;
		
		std::cout << "If you want more informations, enter the Index number, else enter q or quit" << std::endl;
		std::string choice;
		while(true)
		{
			std::cout << '>';
			if(!std::getline(std::cin, choice))
				exit(1);
			if (choice.length() && if_numbers(choice))
			{
				if(stoi(choice) > -1 && stoi(choice) < temp)
				{
					this->_contacts[stoi(choice)].display_index();
					break ;
				}
			}
			else if (choice == "q" || choice == "quit")
				break ;
		}
		}
	std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
}
