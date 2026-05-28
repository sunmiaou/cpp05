/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                   a             +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:42:54 by tlize             #+#    #+#             */
/*   Updated: 2026/05/26 20:52:17 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("DefaultName"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string givenName, int givenGrade): name(givenName)
{
	try
	{
		std::cout << "Bureaucrat constructor called" << std::endl;
		this->applyGrade(givenGrade);
	}
	catch(Bureaucrat::GradeException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &old_crat): name(old_crat.getName() + "copy")
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = old_crat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &old_crat)
{
	std:: cout << "Bureaucrat assignation operator called" << std::endl;
	if (this == &old_crat)
		return *this;
	this->grade = old_crat.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

void				Bureaucrat::incrementGrade()
{
	try
	{
		std::cout << "Grade of " << this->name << " successfuly incremented" << std::endl;
		this->applyGrade(this->grade - 1);
	}
	catch(Bureaucrat::GradeException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

void				Bureaucrat::decrementGrade()
{
	try
	{
		std::cout << "Grade of " << this->name << " successfuly decremented" << std::endl;
		this->applyGrade(this->grade + 1);
	}
	catch(Bureaucrat::GradeException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void				Bureaucrat::applyGrade(int grade)
{
	if (grade > 150 or grade < 1)
		throw Bureaucrat::GradeException();
	else
		this->grade = grade;
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int					Bureaucrat::getGrade() const
{
	return (this->grade);
}

const char			*Bureaucrat::GradeException::what(void) const throw()
{
	return ("Grade not in acceptable range");
}

std::ostream		&operator<<(std::ostream &out, const Bureaucrat &a)
{
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
	return (out);
}

