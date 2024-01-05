/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:21 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/15 10:58:48 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
public :
	Animal();
	Animal(const Animal& copy);
	Animal& operator=(const Animal&);
	
	virtual ~Animal();

	virtual void makeSound() const;
	virtual std::string getType() const;
	
protected:
	std::string _type;
};

#endif