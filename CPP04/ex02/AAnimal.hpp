/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:21 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/08 18:29:26 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
public :
	AAnimal();
	AAnimal(const AAnimal& copy);
	AAnimal& operator=(const AAnimal&);
	
	virtual ~AAnimal();

	virtual void makeSound() const;
	virtual std::string getType() const;
	virtual Brain 		&getBrain(void) const = 0;
protected:
	std::string _type;
};

#endif