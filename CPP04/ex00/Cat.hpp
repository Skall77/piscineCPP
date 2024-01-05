/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:32:09 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/06 17:50:09 by aaudevar         ###   ########.fr       */
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
	
protected:
	std::string _type;
};

#endif