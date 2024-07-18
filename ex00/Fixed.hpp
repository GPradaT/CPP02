/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:25:02 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/18 10:06:16 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class	Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed &src);
		Fixed	&operator=(const Fixed &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
