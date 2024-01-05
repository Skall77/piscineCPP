/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:51:14 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/30 10:28:37 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string	name) : _name(name)
{
	std::cout << "The zombie : " << this->_name << " is alive (undead technically)" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie : " << this->_name << " is dead (Like really dead, not zombie dead)" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}