/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:06:53 by anarama           #+#    #+#             */
/*   Updated: 2024/10/21 20:13:03 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main (void) {
	int arr[] = {5, 3, 2, 9, 1};
	std::vector<int> list(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	for (size_t i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
	
	try {
		std::vector<int>::iterator it = easyfind(list, 2);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const OutOfRangeException& e) {
		std::cout << "Value was not found!" << std::endl;
	}
	try {
		std::vector<int>::iterator it = easyfind(list, 10);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const OutOfRangeException& e) {
		std::cout << "Value was not found!" << std::endl;
	}
	return 0;
}