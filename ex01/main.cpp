/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:42:22 by tlize             #+#    #+#             */
/*   Updated: 2026/05/28 16:39:38 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	std::cout << a.getGrade() << std::endl;
	std::cout << a.getName() << std::endl;
	a.decrementGrade();
	a.incrementGrade();
	std::cout << a.getGrade() << std::endl;

	Bureaucrat b("titouan", 1);
	std::cout << b.getGrade() << std::endl;
	std::cout << b.getName() << std::endl;
	b.incrementGrade();
	b.decrementGrade();
	std::cout << b.getGrade() << std::endl;


	std::cout << a;
	std::cout << b;
}
