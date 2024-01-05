/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:39:33 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/03 15:39:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
			std::string _name;
			AMateria *_slots[4];

	public:
		Character(std::string const& name);
		Character(const Character& copy);
		Character& operator=(const Character&obj);

		~Character();

		virtual std::string const& getName() const;
		void setName(std::string const &name);
		
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		bool isEquiped(AMateria *m);

};
#endif