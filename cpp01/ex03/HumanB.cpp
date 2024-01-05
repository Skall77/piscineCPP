/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:46:10 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/28 09:15:28 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _Weapon(NULL)
{
	std::cout << "Constructor of HumanB called with the name : " << this->_name << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Destructor of HumanB called" << std::endl;
}

void HumanB::attack(void) const
{
	if(this->_Weapon)
		std::cout << this->_name << " attack with their " << this->_Weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
	this->_Weapon = &Weapon;
}
