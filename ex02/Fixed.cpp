/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:57:36 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/20 11:04:45 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "copy assignment operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &src)
{
	return Fixed(toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(const Fixed &src)
{
	return Fixed(toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(const Fixed &src)
{
	return Fixed(toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(const Fixed &src)
{
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

bool	Fixed::operator<(const Fixed &src)
{
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator>(const Fixed &src)
{
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator<=(const Fixed &src)
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator>=(const Fixed &src)
{
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator==(const Fixed &src)
{
	return (this->toFloat() == src.toFloat());
}
