/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:16:06 by anarama           #+#    #+#             */
/*   Updated: 2024/10/22 14:38:54 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>

int main( void ) {
	Span span(5);
	
	try {
		span.addNumber(1);
		span.addNumber(-1);
		span.addNumber(3);
		span.addNumber(9);
		span.addNumber(7);
		span.printList();
		int longest = span.longestSpan();
		std::cout << "longest span: " << longest << std::endl;
		int shortes = span.shortestSpan();
		std::cout << "shortest span: " << shortes << std::endl;
	} catch (...) {
		std::cout << "Whats up bruv" << std::endl;
	}
}
