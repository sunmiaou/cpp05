/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:57:00 by tlize             #+#    #+#             */
/*   Updated: 2026/06/02 15:58:22 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
public:
	Form();
	Form(std::string givenName, int Sign, int Exec);
	Form(const Form &old_form);
	Form &operator=(const Form &old_form);
	~Form();

	const std::string	getName() const;
	const int			getSign() const;
	const int			getExec() const;
	const std::string	isSigned() const;
	void				beSigned(Bureaucrat &crat);
private:
	const std::string	name;
	bool				signedd = false;
	const int			gradeSign;
	const int			gradeExec;
};

std::ostream &operator<<(std::ostream &out, const Form &value);

#endif