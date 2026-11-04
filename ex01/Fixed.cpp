/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:09:04 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 13:20:51 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& copyme)
{
	std::cout << "copy constructor called" << std::endl;
	this->value = copyme.value;	
}

Fixed::Fixed(const int num)
{
	std::cout << "Integer constructor called" << std::endl;
	this->value = num << Fixed::fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = static_cast<int>(std::roundf(number * (1 << Fixed::fractional_bits)));
}

Fixed &Fixed::operator=(const Fixed& assignment)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &assignment)
		this->value = assignment.value;
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return(this->value >> Fixed::fractional_bits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / static_cast<float>(1 << Fixed::fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
	os << value.toFloat();
	return(os);
}
