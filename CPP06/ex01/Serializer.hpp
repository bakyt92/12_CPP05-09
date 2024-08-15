/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 02:29:48 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/15 19:39:49 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
// #include <cstdint>
#include <cstddef> // for std::size_t
typedef std::size_t uintptr_t;

struct Data {
    int i;
    std::string str;
};

class Serializer
{
private:
    Serializer(/* args */);
    ~Serializer();
    Serializer(const Serializer &src);
    Serializer& operator=(const Serializer &rhs);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif