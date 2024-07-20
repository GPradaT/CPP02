/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:04:38 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/20 13:48:24 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( 10 );
	Fixed  b2( 0.1222456f );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 124.242f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "b2 is " << b2 << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a + b = " << a + b << std::endl;	
	std::cout << "a - b = " << a - b << std::endl;	
	std::cout << "a * b = " << a * b << std::endl;	
	std::cout << "a / b = " << a / b << std::endl;	
	std::cout << "a / 0 = " << a / 0 << std::endl;

	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;

	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a is " << a << std::endl;

	Fixed cd = a.min(a, b);
	std::cout << "a value post-method min = " << a << std::endl;
	std::cout << "min(a, b) = " << cd << std::endl;
/*	std::cout << "a == b = " << a == b << std::endl;
	std::cout << "a != b = " << a != b << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	*/
	return 0;
}
