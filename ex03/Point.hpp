/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:52:43 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 15:56:44 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
			const Fixed x;
			const Fixed y;
	public:
			Point();
			Point(const float x, const float y);
			Point(const Point &copyme);
			Point &operator=(const Point &assignment);
			~Point();

			const Fixed &getX(void) const;
			const Fixed &getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
