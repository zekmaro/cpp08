/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:15:10 by anarama           #+#    #+#             */
/*   Updated: 2024/10/22 12:44:41 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <limits>

#include "Span.hpp"

Span::Span( void ) : _N(DEFAULT_N), _list(DEFAULT_N, 0), _isSorted(false) {}

Span::Span( unsigned int N ) : _N(N), _list(N, 0), _isSorted(false) {
	if (N <= 1) {
		throw Span::InvalidListLength();
	}
}

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

const char* Span::InvalidListLength::what() const throw() {
	return "Invalid length N provided! (should be > 1)";
}

int Span::shortestSpan( void ) {
	this->sortList();
	std::vector<unsigned int>::const_iterator it;
	int minDif = std::numeric_limits<unsigned int>::max();
	int tempDif = 0;
	for (it = this->_list.cbegin(); it + 1 != this->_list.cend(); it++) {
		tempDif = *(it + 1) - *it;
		if (tempDif < minDif) {
			minDif = tempDif;
		}
	}
	return minDif;
}

int Span::longestSpan( void ) {
	this->sortList();
	return (this->_list[this->_list.size()] - this->_list[0]);
}

void Span::sortList( void ) {
	if (this->_isSorted == false) {
		std::sort(this->_list.begin(), this->_list.end());
		this->_isSorted = true;
	}
}

void Span::addNumber( unsigned int num ) {
	if (this->_list.size() >= this->_N) {
		throw Span::ArrayIsFull();
	}
	this->_list.push_back(num);
	this->_isSorted = false;
}
