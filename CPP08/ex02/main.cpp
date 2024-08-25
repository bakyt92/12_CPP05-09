/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:47:15 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 22:30:33 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "TOP elem is: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of Mutant stack is: " << mstack.size() << std::endl;
	std::cout << "TOP elem is: " << mstack.top() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Iteration:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	// ADDITIONAL TESTS 
    /* -------------------------------------------------------------------- */
	std::stack<int> s(mstack);
    std::cout << std::endl;
    std::cout << "/ ***** List ***** /" << std::endl;

    std::list< int > lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);

    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();
    ++it;
    --it;
	std::cout << "Iteration:" << std::endl;
    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << std::endl;
        ++lst_it;
    }
    std::list<int> l(lst);
	return 0;
}