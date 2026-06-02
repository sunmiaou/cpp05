/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:55:12 by tlize             #+#    #+#             */
/*   Updated: 2026/06/02 16:34:08 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():  name("DefaultForm"), gradeSign(150), gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string givenName, int Sign, int Exec): 
		name(givenName), 
		gradeSign(Sign), 
		gradeExec(Exec)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &old_form): 
		name(old_form.getName() + "copy"),
		gradeSign(old_form.getSign()),
		gradeExec(old_form.getExec())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = old_form;
}

Form &Form::operator=(const Form &old_form)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this == &old_form)
		return *this;
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

void 				Form::beSigned(Bureaucrat &crat)
{
	if (crat.getGrade() > this->getSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->signedd = false)
	{
		this->signedd = true;
		std::cout << this->getName() << " was signed by " << crat.getName() << std::endl;
	}
}

const std::string	Form::getName() const
{
	return (this->name);
}

const int			Form::getSign() const
{
	return (this->gradeSign);
}

const int			Form::getExec() const
{
	return (this->gradeExec);
}

const std::string	Form::isSigned() const
{
	if (this->signedd)
	{
		return (", has been signed");
	}
	else 
		return (", hasn't been signed");
}

std::ostream		&operator<<(std::ostream &out, const Form &a)
{
	out << a.getName() << " form, grade to sign : "
	<< a.getSign() << ", grade to exec : " << a.getExec()
	<< a.isSigned() << std::endl;
}
