/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:04:12 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 14:49:25 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed &operator=(const Fixed &assignment);
		Fixed(const Fixed& copyme);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed &assignment) const;
		bool operator<(const Fixed &assignment) const;
		bool operator<=(const Fixed &assignment) const;
		bool operator>=(const Fixed &assignment) const;
		bool operator==(const Fixed &assignment) const;
		bool operator!=(const Fixed &assignment) const;
		Fixed operator+(const Fixed &assignment) const;
		Fixed operator-(const Fixed &assignment) const;
		Fixed operator*(const Fixed &assignment) const;
		Fixed operator/(const Fixed &assignment) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
		private:
		int					value;
		static const int	fractional_bits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &value);


#endif