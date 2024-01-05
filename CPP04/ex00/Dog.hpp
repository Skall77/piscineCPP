/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:21:43 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/06 17:50:02 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public :
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog&);
	
	virtual ~Dog();

	virtual void makeSound() const;
	virtual std::string getType() const;
	
protected:
	std::string _type;
};

#endif