/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:09:04 by MP9               #+#    #+#             */
/*   Updated: 2026/10/27 12:54:23 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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
	std::cout << "getRawBits called" << std::endl;
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
