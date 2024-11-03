/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:16:06 by anarama           #+#    #+#             */
/*   Updated: 2024/11/03 13:00:19 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <exception>
#include <ctime>   // For time() to seed srand
#include <cstdlib> // For srand and rand

int main( void ) {
	try {
		Span span(5);
		span.addNumber(1);
		span.addNumber(-1);
		span.addNumber(3);
		span.addNumber(9);
		span.addNumber(7);
		span.printList();
		std::cout << "longest span: " << span.longestSpan() << std::endl;
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Whats up bruv: " << e.what() << std::endl;
	}

	try {
        Span span(10000);
        std::srand(std::time(NULL));
        std::vector<int> randomNumbers;
        randomNumbers.reserve(10000);
        for (int i = 0; i < 10000; ++i) {
            int randomNum = (std::rand() % 100001) - 50000;
            randomNumbers.push_back(randomNum);
        }
        span.addRange(randomNumbers.begin(), randomNumbers.end());
        std::cout << "longest span: " << span.longestSpan() << std::endl;
        std::cout << "shortest span: " << span.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Whats up bruv: " << e.what() << std::endl;
    }
}
