/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:15:13 by anarama           #+#    #+#             */
/*   Updated: 2024/11/03 12:58:46 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

# define DEFAULT_N 0
# define DEFAULT_ADDED 0

class Span {
	private:
		unsigned int _N;
		std::vector<int> _list;
		bool _isSorted;
		unsigned int _added;

	public:
		Span( void );
		Span( unsigned int N );
		Span( const Span& other );
		Span& operator=( const Span& other );
		~Span( void );

		class ArrayIsFullException: public std::exception {
			public:
				const char* what() const throw();
		};
		class NoSpanFoundException: public std::exception {
			public:
				const char* what() const throw();
		};
		class InvalidListLengthException: public std::exception {
			public:
				const char* what() const throw();
		};
		class ListIsNotFullException: public std::exception {
			public:
				const char* what() const throw();
		};

		unsigned int getSize( void );

		void addNumber( unsigned int num );
		
		unsigned int shortestSpan( void );
		unsigned int longestSpan( void );
		
		void sortList( void );
		void checkListSize( void );
		void printList( void );

		template <typename TIterator>
		void addRange( TIterator begin, TIterator end ) {
			while (begin != end) {
				if (this->_added >= this->_N) {
					throw ArrayIsFullException();
				}
				this->_list.push_back(*begin);
				this->_added++;
				begin++;
			}
			this->_isSorted = false;
		}
};

#endif // SPAN_HPP
