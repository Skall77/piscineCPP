/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:21:43 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/08 16:18:08 by aaudevar         ###   ########.fr       */
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
	Brain &getBrain() const;
	void setBrain(Brain const &brain);
	
protected:
	std::string _type;
private:
	Brain	*_brain;
};

#endif