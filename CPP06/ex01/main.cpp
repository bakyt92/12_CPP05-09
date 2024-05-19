/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 02:55:56 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/19 22:49:35 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
    /* Serialize */
    Data* fond = new Data;
    fond->i = 15;
    fond->str = "Hello students of 42";
    uintptr_t raw = {0};
    std::cout << "Before: " << fond << " raw info: " << raw << std::endl;
    raw = Serializer::serialize(fond);
    std::cout << "Ater: " << fond << " raw info: " << raw << std::endl;
    delete fond;

    /* De-serialize */
    Data* oldData = new Data;
    oldData->i = 15;
    oldData->str = "Hello World";
    Data *newData;
    std::cout << "Before pointer: " << oldData << std::endl;
    std::cout << "Before str data: " << oldData->str << std::endl;
    // std::cout << "Before str data for NewData: " << newData->str << std::endl;
    newData = Serializer::deserialize(Serializer::serialize(oldData));
    std::cout << "After pointer: " << newData << std::endl;
    std::cout << "After str data: " << newData->str << std::endl;
    return 0;
}