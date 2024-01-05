/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:18:48 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/31 12:10:42 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_H
#define Fixed_H
#include <iostream>
#include <cmath>

class Fixed 
{
public:

	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed& operator=(const Fixed& copy);
	
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed& operator++();
	Fixed& operator--();

	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& left, Fixed& right);
	static Fixed& max(Fixed& left, Fixed& right);
	static const Fixed& min(const Fixed& left, const Fixed& right);
	static const Fixed& max(const Fixed& left, const Fixed& right);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _value;
	const static int _bits;
};

std::ostream &operator<<(std::ostream &str, Fixed const &copy);


#endif // Fixed_H