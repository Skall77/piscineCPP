/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:02:38 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/03 14:44:24 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type): _type(type)
{
	std::cout << "Constructor AMateria called with type " << this->_type << std::endl;
}

AMateria::AMateria(): _type("")
{
	std::cout << "Defaut Constructor AMateria called" << std::endl;
}

AMateria::AMateria(const AMateria& copy)
{
	*this = copy;
	
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	this->_type = obj._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}
