/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:42:22 by tlize             #+#    #+#             */
/*   Updated: 2026/07/21 20:38:02 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Alice", 1);
        Bureaucrat clerk("Bob", 100);
        Form f("TaxForm", 50, 100);

        std::cout << f;
        clerk.signForm(f);
        std::cout << f;
        boss.signForm(f);
        std::cout << f;
        boss.signForm(f);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form bad("Broken", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
}