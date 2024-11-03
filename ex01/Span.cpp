/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:15:10 by anarama           #+#    #+#             */
/*   Updated: 2024/11/03 12:46:29 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <limits>
#include <iostream>

#include "Span.hpp"

Span::Span( void ) : _N(DEFAULT_N), _list(DEFAULT_N, 0), _isSorted(false), _added(0) {}

Span::Span( unsigned int N ) : _N(N), _list(0, 0), _isSorted(false), _added(0) {
	if (N <= 1) {
		throw Span::InvalidListLengthException();
	}
}

Span::Span( const Span& other ) : _N(other._N), _list(other._list), _added(other._added){}

Span& Span::operator=( const Span& other ) {
	if (this != &other) {
		this->_N = other._N;
		this->_list = other._list;
		this->_isSorted = other._isSorted;
		this->_added = other._added;
	}
	return *this;
}

Span::~Span( void ) {}

const char* Span::ArrayIsFullException::what() const throw() {
	return "Trying to add new elemt in already fulled array!";
}

const char* Span::NoSpanFoundException::what() const throw() {
	return "No span found";
}

const char* Span::InvalidListLengthException::what() const throw() {
	return "Invalid length N provided! (should be > 1)";
}

const char* Span::ListIsNotFullException::what() const throw() {
	return "List is empty. No span possible";
}

unsigned int Span::shortestSpan( void ) {
	this->checkListSize();
	this->sortList();
	std::vector<int>::iterator it;
	unsigned int minDif = std::numeric_limits<int>::max();
	unsigned int tempDif = 0;
	for (it = this->_list.begin(); it + 1 != this->_list.end(); it++) {
		tempDif = *(it + 1) - *it;
		if (tempDif < minDif) {
			minDif = tempDif;
		}
	}
	return minDif;
}

unsigned int Span::longestSpan( void ) {
	this->checkListSize();
	this->sortList();
	return (this->_list[this->_N - 1] - this->_list[0]);
}

void Span::sortList( void ) {
	if (this->_isSorted == false) {
		std::sort(this->_list.begin(), this->_list.end());
		this->_isSorted = true;
	}
}

void Span::addNumber( unsigned int num ) {
	if (this->_added >= this->_N) {
		throw ArrayIsFullException();
	}
	this->_list.push_back(num);
	this->_added++;
	this->_isSorted = false;
}

void Span::checkListSize( void ) {
	if (this->_added < this->_N) {
		throw ListIsNotFullException();
	}
}

void Span::printList( void ) {
	std::vector<int>::iterator it;
	for (it = this->_list.begin(); it != this->_list.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

unsigned int Span::getSize( void ) {
	return this->_N;
}
