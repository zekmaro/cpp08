/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:15:10 by anarama           #+#    #+#             */
/*   Updated: 2024/10/21 21:53:39 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#include "Span.hpp"

Span::Span( void ) : _N(DEFAULT_N), _list(DEFAULT_N, 0), _isSorted(false) {}

Span::Span( unsigned int N ) : _N(N), _list(N, 0), _isSorted(false) {}

Span::Span( const Span& other ) : _N{other._N}, _list(other._list) {}

Span& Span::operator=( const Span& other ) {
	if (this != &other) {
		this->_N = other._N;
		this->_list = other._list;
		this->_isSorted = other._isSorted;
	}
	return *this;
}

Span::~Span( void ) {}

const char* Span::ArrayIsFull::what() const throw() {
	return "Trying to add new elemt in already fulled array!";
}

const char* Span::NoSpanFound::what() const throw() {
	return "No span found";
}

int Span::shortestSpan( void ) {
	if (this->_isSorted == false) {
		std::sort(this->_list.begin(), this->_list.end());
		this->_isSorted = true;
	}
	std::vector<unsigned int>::iterator it;
	for (it = this->_list.cbegin(); it != this->_list.cend(); it++) {
		
	}
}

int Span::longestSpan( void ) {
	
}

void Span::sortList( void ) {
	
}

void Span::addNumber( unsigned int num ) {
	if (this->_list.size() >= this->_N) {
		throw Span::ArrayIsFull();
	}
	this->_list.push_back(num);
	this->_isSorted = false;
}
