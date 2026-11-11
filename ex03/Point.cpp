/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:52:45 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 15:52:46 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &copyme) : x(copyme.x), y(copyme.y)
{
}

// x and y are const: they cannot change after construction,
// so assignment has nothing it can copy.
Point &Point::operator=(const Point &assignment)
{
	(void)assignment;
	return (*this);
}

Point::~Point(void)
{
}

const Fixed &Point::getX(void) const
{
	return (this->x);
}

const Fixed &Point::getY(void) const
{
	return (this->y);
}
