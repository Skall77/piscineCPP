/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:39:30 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/03 15:50:34 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name): _name(name), _slots()
{
	std::cout << "Constructor Character called with the name : " << this->_name << std::endl;
}

Character::Character(const Character& copy): _slots()
{
	*this = copy;
	std::cout << "Character " << this->_name << " coppied" << std::endl;
}

Character& Character::operator=(const Character&obj)
{
	this->_name = obj._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i])
			delete this->_slots[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (obj._slots[i])
			this->_slots[i] = obj._slots[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_slots[i])
			delete this->_slots[i];
	std::cout << "Destructor Character called" << std::endl;
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void Character::setName(std::string const &name)
{
	this->_name = name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_slots[i] == NULL)
		{
			if (this->isEquiped(m))
				this->_slots[i] = m->clone();
			else
				this->_slots[i] = m;
			std::cout << "The Materia " << this->_slots[i]->getType() << " have been equiped to " << this->getName();
			std::cout << " in the slot number " << i << std::endl;
			return ;
		}
	}
	if (m)
		std::cout << "No more slot available, please unequip() before trying to equip() more Materia" << std::endl;
	else
		std::cout << "Invalid Materia" << std::endl;
	if (!this->isEquiped(m))
		delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_slots[idx])
	{
		std::cout << "The Materia " << this->_slots[idx]->getType() << " have been unequiped by " << this->getName() << std::endl;
		this->_slots[idx] = NULL;
	}
	else if (idx < 0 || idx > 3)
		std::cout << "There is only 4 slots available, please chose a number between 0 and 3" << std::endl;
	else
		std::cout << "This slot is already empty !" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_slots[idx])
		this->_slots[idx]->use(target);
	else if (idx < 0 || idx > 3)
		std::cout << "There is only 4 slots available, please chose a number between 0 and 3" << std::endl;
	else
		std::cout << "This slot is empty !" << std::endl;
}

bool Character::isEquiped(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (this->_slots[i] == m)
				return (true);
	return (false);
}

