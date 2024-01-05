/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:23:21 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/27 10:23:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:

		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& obj);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size();

		class OutOfBoundsException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

	private:
		T				*_data;
		unsigned int	_size;
};

template<typename T>
Array<T>::Array() : _data(new T[0]), _size(0)
{
	std::cout << "Constructor for empty Array called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n): _data(new T[n]), _size(n)
{
	std::cout << "Constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array& copy): _data(new T[copy._size]), _size(copy._size)
{
	*this = copy;
	std::cout << "Constructor copy called" << std::endl;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	delete[] this->_data;
	this->_data = new T[obj._size];
	this->_size = obj._size;
	for (unsigned int i = 0; i < obj._size; i++)
		this->_data[i] = obj._data[i];
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_data;
	std::cout << "Destructor called" << std::endl;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return this->_data[index];
}

template<typename T>
unsigned int Array<T>::size()
{
	return (this->_size);
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Exception: You're out of bounds with this index! ");
}

#endif