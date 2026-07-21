/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:55:12 by tlize             #+#    #+#             */
/*   Updated: 2026/07/21 20:38:12 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("DefaultForm"), signedd(false), gradeSign(150), gradeExec(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &givenName, int Sign, int Exec)
    : name(givenName), signedd(false), gradeSign(Sign), gradeExec(Exec)
{
    if (Sign > 150 || Exec > 150)
        throw Form::GradeTooLowException();
    if (Sign < 1 || Exec < 1)
        throw Form::GradeTooHighException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &old_form)
    : name(old_form.getName()), signedd(old_form.signedd),
      gradeSign(old_form.getSign()), gradeExec(old_form.getExec())
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &old_form)
{
    std::cout << "Form assignation operator called" << std::endl;
    if (this == &old_form)
        return *this;
    this->signedd = old_form.signedd;
    return *this;
}
Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat &crat)
{
    if (crat.getGrade() > this->getSign())
        throw Form::GradeTooLowException();
    if (!this->signedd)
    {
        this->signedd = true;
        std::cout << this->getName() << " was signed by " << crat.getName() << std::endl;
    }
    else
        std::cout << this->getName() << " is already signed" << std::endl;
}

std::string			Form::getName() const
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

std::string			Form::isSigned() const
{
	if (this->signedd)
	{
		return (", has been signed");
	}
	else 
		return (", hasn't been signed");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Form grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Form grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &a)
{
    out << a.getName() << " form, grade to sign : "
        << a.getSign() << ", grade to exec : " << a.getExec()
        << a.isSigned() << std::endl;
    return (out);
}
