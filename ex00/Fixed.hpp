/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:04:12 by MP9               #+#    #+#             */
/*   Updated: 2026/10/27 12:51:13 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copyme);
		Fixed &operator=(const Fixed& assignment);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
	
	private:
		int value;
		static const int fractional_bits = 8;
};


#endif