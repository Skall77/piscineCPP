/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:59 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/10 15:57:58 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource(): _slots()
{
	std::cout << "Constructor MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy): _slots()
{
	for (int i = 0; i < 4; i++)
		if (this->_slots[i])
			this->_slots[i] = copy._slots[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource&obj)
{
	(void)obj;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->_slots[i])
			delete this->_slots[i];
	std::cout << "Destructor MateriaSource called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_slots[i] == NULL)
		{
			if (this->isLearned(m))
				this->_slots[i] = m->clone();
			else
				this->_slots[i] = m;
			std::cout << "The Materia " << this->_slots[i]->getType() << " have been learned to the slot number " << i << std::endl;
			return ;
		}
	}
	if (m)
		std::cout << "No more slot available, you can't learn new materia" << std::endl;
	else
		std::cout << "Invalid Materia" << std::endl;
	if (!this->isLearned(m))
		delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] && this->_slots[i]->getType() == type)
			return (this->_slots[i]->clone());
	}
	std::cout << "Invalid Materia type" << std::endl;
	return NULL;
}

bool MateriaSource::isLearned(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if(this->_slots[i] == m)
			return (true);
	return (false);
}
