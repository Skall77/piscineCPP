/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:25:50 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/31 12:22:07 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bits = 8;

////////////////// Constructors /////////////////////////

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed::Fixed(const int value) : _value(value << Fixed::_bits)
{

}

Fixed::Fixed(const float value) : _value(roundf(value *(1 << Fixed::_bits)))
{

}

////////////////// Arithmetic Operators //////////////

Fixed& Fixed::operator=(const Fixed& copy)
{
	this->_value = copy.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed ret;
	ret._value = (this->_value + other._value);
	return ret;
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed ret;
	ret._value = (this->_value - other._value);
	return ret;
}


Fixed Fixed::operator*(const Fixed& other)
{
	Fixed ret(this->toFloat() * other.toFloat());
	return ret;
}


Fixed Fixed::operator/(const Fixed& other)
{
	Fixed ret(this->toFloat() / other.toFloat());
	return ret;
}

////////////////// Comparison operators //////////////

bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other._value;
}

////////////// Incrementation / Decrementation //////////

Fixed& Fixed::operator++()
{
	++(this->_value);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	
	++(this->_value);
	return ret;
}

Fixed& Fixed::operator--()
{
	--(this->_value);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	
	--(this->_value);
	return ret;
}

////////////// MIN / MAX /////////////////////

Fixed& Fixed::min(Fixed& left, Fixed& right)
{
	if (left < right)
		return (left);
	return right;
}

Fixed& Fixed::max(Fixed& left, Fixed& right)
{
	if (left > right)
		return (left);
	return right;
}

const Fixed& Fixed::min(const Fixed& left, const Fixed& right)
{
	if (left < right)
		return (left);
	return right;
}

const Fixed& Fixed::max(const Fixed& left, const Fixed& right)
{
	if (left > right)
		return (left);
	return right;
}

//////////// Destructor /////////////////

Fixed::~Fixed()
{
}

//////////// Member functions ////////////

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << Fixed::_bits);
}

int Fixed::toInt(void) const
{
	return this->_value >> Fixed::_bits;
}

/////////// insertion flux ////////////////

std::ostream &operator<<(std::ostream &str, Fixed const &copy)
{
	return (str << copy.toFloat());
}
