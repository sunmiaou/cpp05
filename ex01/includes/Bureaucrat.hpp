/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:42:50 by tlize             #+#    #+#             */
/*   Updated: 2026/07/21 20:13:20 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;


class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string &givenName, int givenGrade);
    Bureaucrat(const Bureaucrat &old_crat);
    Bureaucrat &operator=(const Bureaucrat &old_crat);
    ~Bureaucrat();

    std::string	getName() const;
    int			getGrade() const;
    void		incrementGrade();
    void		decrementGrade();
	void		signForm(Form &form);

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
    void                applyGrade(int grade);

    const std::string   name;
    int                 grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);

#endif