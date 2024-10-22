/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:15:13 by anarama           #+#    #+#             */
/*   Updated: 2024/10/22 14:37:12 by anarama          ###   ########.fr       */
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

		class ArrayIsFullException: std::exception {
			public:
				const char* what() const throw();
		};
		class NoSpanFoundException: std::exception {
			public:
				const char* what() const throw();
		};
		class InvalidListLengthException: std::exception {
			public:
				const char* what() const throw();
		};
		class ListIsNotFullException: std::exception {
			public:
				const char* what() const throw();
		};


		void addNumber( unsigned int num );
		
		unsigned int shortestSpan( void );
		unsigned int longestSpan( void );
		
		void sortList( void );
		void checkListSize( void );
		void printList( void );
};

#endif // SPAN_HPP
