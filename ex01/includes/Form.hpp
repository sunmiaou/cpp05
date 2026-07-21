/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:57:00 by tlize             #+#    #+#             */
/*   Updated: 2026/07/21 20:38:13 by tlize            ###   ########.fr       */
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
	Form(const std::string &givenName, int Sign, int Exec);
	Form(const Form &old_form);
	Form &operator=(const Form &old_form);
	~Form();

	std::string			getName() const;
	const int			getSign() const;
	const int			getExec() const;
	std::string			isSigned() const;
	void				beSigned(Bureaucrat &crat);

	//Exceptions
	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
private:
	const std::string	name;
	bool				signedd;
	const int			gradeSign;
	const int			gradeExec;
};

std::ostream &operator<<(std::ostream &out, const Form &value);

#endif