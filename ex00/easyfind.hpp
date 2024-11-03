/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:06:51 by anarama           #+#    #+#             */
/*   Updated: 2024/11/03 12:30:48 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

class OutOfRangeException: public std::exception {
	public:
		const char* what() const throw() {
			return "Accesing entry out of range!";
		}
};

template <typename T>
typename T::iterator easyfind( T& data, int n ) {
	typename T::iterator it;
	it = std::find(data.begin(), data.end(), n);
	if (it != data.end()) {
		return it;
	} else {
		throw OutOfRangeException();
	}
}

#endif // EASYFIND_HPP
