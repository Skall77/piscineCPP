#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Claptrap"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	this->_max_hit_point = _hit_point;
	std::cout << "default ClapTrap constructed called " << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	this->_max_hit_point = _hit_point;
	std::cout << "ClapTrap " << this->_name << " Created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_attack_damage = copy._attack_damage;
	this->_energy_point = copy._energy_point;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " Destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		this->_energy_point--;
		std::cout << "Claptrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
	}
	else if (this->_energy_point != 0)
		std::cout << "Claptrap "<< this->_name << " is K.O. :(" << std::endl;
	else
		std::cout << "Claptrap "<< this->_name << " is out of energy, they can't do anything anymore :(" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_point -= amount;
	if (this->_hit_point > this->_max_hit_point)
			this->_hit_point = 0;
	std::cout << "Claptrap " << this->_name << " took " << amount;
	std::cout << " points of damage, they have " << this->_hit_point;
	std::cout << " hit points left !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		this->_hit_point += amount; 
		if (this->_hit_point > this->_max_hit_point)
			this->_hit_point = this->_max_hit_point;
		this->_energy_point--;
		std::cout << "Claptrap " << this->_name << " repaired himself " << amount;
		std::cout << " hit points, they now have " << this->_hit_point;
		std::cout << " hit points !" << std::endl;
	}
	else if (this->_energy_point != 0)
		std::cout << "Claptrap "<< this->_name << " is K.O. :(" << std::endl;
	else
		std::cout << "Claptrap "<< this->_name << " is out of energy, he can't do anything anymore :(" << std::endl;
	
}

