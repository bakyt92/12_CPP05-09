/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 02:55:56 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/19 03:08:42 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
    Data* fond = new Data;
    fond->i = 15;
    fond->str = "Hello students of 42";
    uintptr_t raw = {0};
    std::cout << "Before: " << fond << " raw info: " << raw << std::endl;
    raw = Serializer::serialize(fond);
    std::cout << "Ater: " << fond << " raw info: " << raw << std::endl;
    delete fond;
    return 0;
}