/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:57:36 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/20 13:47:50 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_rawBits = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int nb)
{
	_rawBits = nb << _fractionalBits;
}

Fixed::Fixed(const float nb)
{
	_rawBits = roundf(nb * (1 << _fractionalBits));
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

int	Fixed::getRawBits(void) const
{
	return _rawBits;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	this->_rawBits = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &src) const
{
	return Fixed(toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	return Fixed(toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	return Fixed(toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	if (src.getRawBits() == 0)
		return Fixed();
	return Fixed(toFloat() / src.toFloat());
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return out;
}

int	Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

float	Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

bool	Fixed::operator<(const Fixed &src) const
{
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator>(const Fixed &src) const
{
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator<=(const Fixed &src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator>=(const Fixed &src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator==(const Fixed &src) const
{
	return (this->toFloat() == src.toFloat());
}

Fixed	&Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++(*this);	
	return temp;
}

Fixed	&Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--(*this);
	return temp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return b;
	return a;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return b;
	return a;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}
