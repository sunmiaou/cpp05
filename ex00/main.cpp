/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlize <tlize@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:42:22 by tlize             #+#    #+#             */
/*   Updated: 2026/07/21 20:59:37 by tlize            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat def; // constructeur par défaut, pas d'exception possible
        std::cout << def.getGrade() << std::endl;
        std::cout << def.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bad("Bob", 151); // grade invalide -> exception attendue
        std::cout << bad; // ne sera jamais atteint
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bad2("Carol", 0); // grade invalide -> exception attendue
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    return (0);
}
