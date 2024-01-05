/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:00:04 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/30 13:04:51 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &Weapon);
		~HumanA(void);
		void attack(void) const;
		void setWeapon(Weapon Weapon);
		
	private:
		std::string _name;
		Weapon &_Weapon;
		
};

#endif