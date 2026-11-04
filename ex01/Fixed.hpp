/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:04:12 by MP9               #+#    #+#             */
/*   Updated: 2026/11/04 13:18:08 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed& copyme);
		Fixed &operator=(const Fixed& assignment);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
		private:
		int					value;
		static const int	fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& value);


#endif