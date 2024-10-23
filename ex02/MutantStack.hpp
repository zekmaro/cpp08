/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:00:44 by anarama           #+#    #+#             */
/*   Updated: 2024/10/23 12:19:02 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack( void );
		MutantStack( const MutantStack& other );
		MutantStack& operator=( const MutantStack& other );
		~MutantStack( void );

		class iterator {
			
		};
};

#endif // MUTANT_STACK_HPP