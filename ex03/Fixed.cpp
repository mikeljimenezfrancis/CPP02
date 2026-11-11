/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:09:04 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 15:59:26 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <cstdint>

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const Fixed& copyme)
{
	this->value = copyme.value;	
}

Fixed::Fixed(const int num)
{
	this->value = num << Fixed::fractional_bits;
}

Fixed::Fixed(const float number)
{
	this->value = static_cast<int>(std::roundf(number * (1 << Fixed::fractional_bits)));
}

Fixed &Fixed::operator=(const Fixed& assignment)
{
	if (this != &assignment)
		this->value = assignment.value;
	return(*this);
}

Fixed::~Fixed() {}

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

std::ostream &operator<<(std::ostream &os, const Fixed &value)
{
	os << value.toFloat();
	return(os);
}

bool Fixed::operator>(const Fixed &assignment) const
{
	return(this->value > assignment.value);
}

bool Fixed::operator<(const Fixed &assignment) const
{
	return(this->value < assignment.value);
}

bool Fixed::operator<=(const Fixed &assignment) const
{
	return(this->value <= assignment.value);
}

bool Fixed::operator>=(const Fixed &assignment) const
{
	return(this->value >= assignment.value);
}

bool Fixed::operator!=(const Fixed &assignment) const
{
	return(this->value != assignment.value);
}

bool Fixed::operator==(const Fixed &assignment) const
{
	return(this->value == assignment.value);
}

Fixed Fixed::operator+(const Fixed &assignment) const
{
	Fixed result;
	result.value = this->value + assignment.value;
	return(result);
}

Fixed Fixed::operator-(const Fixed &assignment) const
{
	Fixed result;
	result.value = this->value - assignment.value;
	return(result);
}

Fixed Fixed::operator*(const Fixed &assignment) const
{
	Fixed result;
	int64_t big = static_cast<int64_t>(this->value) * assignment.value;
	result.value = big >> fractional_bits;
	return(result);
}

Fixed Fixed::operator/(const Fixed &assignment) const
{
	Fixed result;
	int64_t big = static_cast<int64_t>(this->value) << fractional_bits;
	result.value = big / assignment.value;
	return(result);
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	++(*this);
	return(old);
}

Fixed &Fixed::operator++()
{
	++value;
	return(*this);	
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	--(*this);
	return(old);
}

Fixed &Fixed::operator--()
{
	--value;
	return(*this);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if(a > b)
		return(b);
	return(a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if(a < b)
		return(b);
	return(a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return(b);
	return(a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return(b);
	return(a);
}
