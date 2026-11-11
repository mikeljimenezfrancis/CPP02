/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:52:54 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 15:52:55 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Cross product of the vectors (b - a) and (p - a).
// > 0: p is left of the edge a->b
// < 0: p is right of it
// = 0: p is exactly on the line through a and b
static Fixed cross(Point const &a, Point const &b, Point const &p)
{
	return ((b.getX() - a.getX()) * (p.getY() - a.getY())
		- (b.getY() - a.getY()) * (p.getX() - a.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const zero(0);
	Fixed const d1 = cross(a, b, point);
	Fixed const d2 = cross(b, c, point);
	Fixed const d3 = cross(c, a, point);

	// On an edge or vertex -> false (required by the subject)
	if (d1 == zero || d2 == zero || d3 == zero)
		return (false);
	// Inside: the point is on the same side of all three edges
	return ((d1 > zero && d2 > zero && d3 > zero)
		|| (d1 < zero && d2 < zero && d3 < zero));
}
