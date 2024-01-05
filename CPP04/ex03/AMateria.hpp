/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:48:29 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/03 14:43:42 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
			std::string _type;

	public:
		AMateria(std::string const& type);
		AMateria();
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria&);

		virtual ~AMateria();

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;

};

#endif // AMATERIA_HPP