/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:31 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 21:33:26 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137),
    _target("unnamed")
{
    std::cout << "ShrubberyCreationForm constructor is called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137),
    _target(target)
{
    std::cout << "ShrubberyCreationForm constructor with target is called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) 
    : AForm(src), _target(src._target)
{
    *this = src; 
}
   
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        {
            AForm::operator=(rhs);
            this->_target = rhs._target;
        }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget()
{
    return this->_target;
}

void ShrubberyCreationForm::execute (const Bureaucrat &executor) const
{
    std::cout << "2_Execute Robotomy Shrubbery is called" << std::endl;
    toExecute(executor);
    try 
    {
        std::string temp = this->_target + "_shrubbery";
        const char* filename1 = temp.c_str();
        std::ofstream fd(filename1);
        if (!fd.is_open())
            throw std::ios_base::failure("Failed to open file.");
        std::cout << "Writing to file: >> " << std::endl;
        fd << "              " << std::endl;
fd << "          _{'\' _{'\'{'\'/}/}/}__ " << std::endl <<
    "         {/{/'\'}{/{/'\'}('\'}{/'\'} _" << std::endl <<
    "        {/{/'\'}{/{/'\'}(_)'\'}{/{/'\'}  _" << std::endl <<
    "     {'\'{/('\'}'\'}{/{/'\'}'\'}{/){/'\'}'\'} /'\'}" << std::endl <<
    "    {/{/(_)/}{'\'{/)'\'}{'\'(_){/}/}/}/}" << std::endl <<
    "   _{'\'{/{/{'\'{/{/(_)/}/}/}{'\'(/}/}/}" << std::endl <<
    "  {/{/{'\'{'\'{'\'(/}{'\'{'\'/}/}{'\'}(_){'\'/}'\'}" << std::endl <<
    "  _{'\'{/{'\'{/(_)'\'}/}{/{/{/'\'}'\'})'\'}{/'\'}" << std::endl <<
    " {/{/{'\'{'\'(/}{/{'\'{'\'{'\'/})/}{'\'(_)/}/}'\'}" << std::endl <<
    "  {'\'{'\'/}(_){'\'{'\'{'\'/}/}(_){'\'/}{'\'/}/})/}" << std::endl <<
    "   {/{'\'{'\'/}{/{'\'{'\'{'\'/}/}{'\'{'\'/}/}'\'}(_)" << std::endl <<
    "  {/{'\'{'\'/}{/){'\'{'\'{'\'/}/}{'\'{'\'(/}/}'\'}/}" << std::endl <<
    "   {/{'\'{'\'/}(_){'\'{'\'{'\'(/}/}{'\'(_)/}/}'\'}" << std::endl <<
    "     {/({/{'\'{/{'\'{'\'/}(_){'\'/}/}'\'}/}('\'}" << std::endl <<
    "      (_){/{'\'/}{'\'{'\'/}/}{'\'{'\')/}/}(_)" << std::endl <<
    "        {/{/{'\'{'\'/}{/{'\'{'\'{'\'(_)/} " << std::endl <<
    "         {/{'\'{'\'{'\'/}/}{'\'{\\}/} " << std::endl;
fd<<"          {){/ {'\'/}{'\'/} '\'}'\'} " << std::endl;
fd<<"          (_)  '\'.-'.-/ " << std::endl;
fd<<"      __...--- |'-.-'| --...__" << std::endl <<
    "...--    .-'   |'-.-'|  ' -.  --..__ " << std::endl <<
    "    ' .  . '   |.'-._| '  . .  '   Shrubbery Tree " << std::endl <<
    "'-  '    .--'  | '-.'|    .  '  . ' " << std::endl <<
    "      ' ..     |'-_.-| "<< std::endl <<
    " '  .       _.-|-._ -|-._  .  '  . " << std::endl <<
    "          .'   |'- .-|   '. " << std::endl <<
    " '   ' .  '.   `-._.-�   .'  '  - . " << std::endl <<
    ".-' '        '-._______.-'     '  . " << std::endl <<
    "     .      ~,                         " << std::endl <<
    " .       .   |    .    ' '-. " << std::endl;
    fd << "                                  "<< std::endl;
    fd << "--------->> Author of tree is ufitzhug (copied from open-source) <<---------"<< std::endl;
        fd.close();
        std::cout << "File is finalised " << std::endl;
    }
    catch (const std::ios_base::failure& ex) 
    {
        std::cout << "File I/O error" << std::endl;
    }
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    std::cout << "ShrubberyCreationForm destructor is called." << std::endl;
}

