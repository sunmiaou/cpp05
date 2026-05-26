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
	catch(Bureaucrat::HighGradeException &e)
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void				Bureaucrat::applyGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::LowGradeException();
	else if (grade < 1)
		throw Bureaucrat::HighGradeException();
	else
		this->grade = grade;
}

const std::string	Bureaucrat::getName()
{
	return (this->name);
}

int					Bureaucrat::getGrade()
{
	return (this->grade);
}

const char *Bureaucrat::LowGradeException::what(void) const throw()
{
	return ("Grade cannot be this low");
}

const char *Bureaucrat::HighGradeException::what(void) const throw()
{
	return ("Grade cannot be this high");
}