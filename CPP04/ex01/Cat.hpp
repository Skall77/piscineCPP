/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:32:09 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/08 16:11:28 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public :
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat&);
	
	virtual ~Cat();

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