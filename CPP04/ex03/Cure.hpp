/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:24:24 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/10 14:37:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"

class Cure : public AMateria
{

	public:
		Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure&);

		virtual ~Cure();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

};

#endif 