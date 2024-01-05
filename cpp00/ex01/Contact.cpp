/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:12:57 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/27 15:46:29 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	this->_last_name= std::string();
	this->_first_name= std::string();
	this->_nickname= std::string();
	this->_phone_number= std::string();
	this->_darkest_secret= std::string();
	this->_index = -1;
	this->_temp = std::string();
}

Contact::~Contact()
{
}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name= first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

/*ADD a contact by asking them informations */

void	Contact::set_all(int index)
{
	this->_index = index;

	while (this->_temp.length() == 0)
	{
		std::cout << "First Name : ";
		if(!std::getline(std::cin, this->_temp))
			exit(1);
	}
	set_first_name(this->_temp);
	this->_temp = std::string();
	
	while (this->_temp.length() == 0)
	{
		std::cout << "Last Name : ";
		if(!std::getline(std::cin, this->_temp))
			exit(1);
	}
	set_last_name(this->_temp);
	this->_temp = std::string();
	
	while (this->_temp.length() == 0)
	{
		std::cout << "Nickname : ";
		if(!std::getline(std::cin, this->_temp))
			exit(1);
	}
	set_nickname(this->_temp);
	this->_temp = std::string();

	while (this->_temp.length() == 0)
	{
		std::cout << "Phone Number : ";
		if(!std::getline(std::cin, this->_temp))
			exit(1);
	}
	set_phone_number(this->_temp);
	this->_temp = std::string();
	
	while (this->_temp.length() == 0)
	{
		std::cout << "Your Darkest Secret : ";
		if(!std::getline(std::cin, this->_temp))
			exit(1);
	}
	set_darkest_secret(this->_temp);
	this->_temp = std::string();
}

/*Show contact information in a list */

void	Contact::display_search(void) const
{
	std::cout << "|" << std::setw(10) << this->_index;
	
	std::cout << "|";
	if (this->_first_name.length() > 10)
		std::cout << this->_first_name.substr(0,9) << ".";
	else
		std::cout  << std::setw(10) << this->_first_name;
	
	std::cout << "|";
	if (this->_last_name.length() > 10)
		std::cout << this->_last_name.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->_last_name;
	
	std::cout << "|";
	if (this->_nickname.length() > 10)
		std::cout << this->_nickname.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << this->_nickname;
	
	std::cout << "|" << std::endl;
}

/*Show contact information for a specific index */

void		Contact::display_index(void) const
{
	std::cout << "Contact " << this->_index << std::endl;
	
	std::cout << "First Name : ";
	std::cout << this->_first_name << std::endl;

	std::cout << "Last Name : ";
	std::cout << this->_last_name << std::endl;

	std::cout << "Nickname : ";
	std::cout << this->_nickname << std::endl;

	std::cout << "Phone Number : ";
	std::cout << this->_phone_number << std::endl;

	std::cout << "Darkest Secret : ";
	std::cout << this->_darkest_secret << std::endl;
}