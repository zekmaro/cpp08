/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:00:44 by anarama           #+#    #+#             */
/*   Updated: 2024/10/24 12:08:44 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack( void ) : std::stack<T>() {}
		MutantStack( const MutantStack& other ) : std::stack<T>(other) {}
		MutantStack& operator=( const MutantStack& other ) {
			if (this != &other) {
				this->c = other.c;
			}
			return *this;
		}
		~MutantStack( void ) {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
   		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() {
			return std::stack<T>::c.begin();
		}
		iterator end() {
			return std::stack<T>::c.end();
		}
		const_iterator cbegin() {
			return std::stack<T>::c.cbegin();
		}
		const_iterator cend() {
			return std::stack<T>::c.cend();
		}
		reverse_iterator rbegin() {
			return std::stack<T>::c.rbegin();
		}
		reverse_iterator rend() {
			return std::stack<T>::c.rend();
		}
		const_reverse_iterator crbegin() {
			return std::stack<T>::c.rbegin();
		}
		const_reverse_iterator crend() {
			return std::stack<T>::c.rend();
		}
};

#endif // MUTANT_STACK_HPP
