/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:42:50 by tlize             #+#    #+#             */
/*   Updated: 2026/02/02 19:24:13 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &old_crat);
	Bureaucrat &operator=(const Bureaucrat &old_crat);
	~Bureaucrat();

	const std::string	getName();
	int					getGrade();
	void				incrementGrade();
	void				decrementGrade();
private:
	const std::string	name;
	int					grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);

#endif