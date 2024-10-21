/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:15:13 by anarama           #+#    #+#             */
/*   Updated: 2024/10/21 21:45:10 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

# define DEFAULT_N 0

class Span {
	private:
		unsigned int _N;
		std::vector<unsigned int> _list;
		bool _isSorted;

	public:
		Span( void );
		Span( unsigned int N );
		Span( const Span& other );
		Span& operator=( const Span& other );
		~Span( void );

		class ArrayIsFull: std::exception {
			public:
				const char* what() const throw();
		};
		class NoSpanFound: std::exception {
			public:
				const char* what() const throw();
		};

		void addNumber( unsigned int num );
		
		int shortestSpan( void );
		int longestSpan( void );
		
		void sortList( void );
};

#endif // SPAN_HPP