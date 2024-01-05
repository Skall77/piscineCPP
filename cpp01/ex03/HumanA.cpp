/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:59:56 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/28 09:15:33 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : _name(name), _Weapon(Weapon)
{
	std::cout << "Constructor of HumanA called with the name : " << this->_name << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Destructor of HumanA called" << std::endl;
}

void HumanA::attack(void) const
{
	std::cout << this->_name << " attack with their " << this->_Weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon Weapon)
{
	this->_Weapon = Weapon;
}
