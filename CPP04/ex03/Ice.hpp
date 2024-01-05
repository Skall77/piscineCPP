/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:08:54 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/10 14:37:34 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"

class Ice : public AMateria
{

	public:
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice&);

		virtual ~Ice();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

};

#endif // ICE_HPP