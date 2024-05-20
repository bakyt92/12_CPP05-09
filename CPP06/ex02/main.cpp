/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:56:06 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/20 18:56:14 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand(time(NULL));
	usleep(1000055); // to generate different values (to change time)
	int i = rand();
	if (i % 3 == 0)
		return (new A);
	else if (i % 3 == 1)
		return (new B);
	else 
		return (new C);
}
    void identify(Base* p)
{
	if (dynamic_cast<A*>(p) )
		std::cout << "This pointer is class A instance" << std::endl;
	else if (dynamic_cast<B*>(p) )
		std::cout << "This pointer is class B instance" << std::endl;
	else if (dynamic_cast<C*>(p) )
		std::cout << "This pointer is class C instance" << std::endl;
	return ;
}
    void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "This pointer is class A instance" << std::endl;
		(void)a;
	}
	catch(const std::exception& e) {};
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "This pointer is class B instance" << std::endl;
		(void)b;
	}
	catch(const std::exception& e) {};
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "This pointer is class C instance" << std::endl;
		(void)c;
	}
	catch(const std::exception& e) {};
	
}

int main ()
{
	Base *class_1 = generate();
	Base *class_2 = generate();
	Base *class_3 = generate();
	Base *class_4 = generate();
	
	std::cout << "Class 1" << std::endl;
	identify(class_1);
	std::cout << "Class 2" << std::endl;
	identify(class_2);
	std::cout << "Class 3 (two options)" << std::endl;
	identify(class_3);
	identify(*class_3);
	std::cout << "Class 4 (two options)" << std::endl;
	identify(class_4);
	identify(*class_4);

	delete class_1;
	delete class_2;
	delete class_3;
	delete class_4;
	return 0;
}


