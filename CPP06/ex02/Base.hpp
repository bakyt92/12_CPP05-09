/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:55:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/19 23:05:52 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
private:
    /* data */
public:
    Base(/* args */);
    ~Base();
    Base * generate(void);
    void identify(Base* p);
    void identify(Base& p);
};



#endif