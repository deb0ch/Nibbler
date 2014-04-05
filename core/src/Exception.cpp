//
// Exception.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 10:02:24 2014 chauvo_t
// Last update Sat Apr  5 13:19:51 2014 chauvo_t
//

#include "../../interface/Exception.hh"

Exception::Exception(const std::string &msg)
  : _error(msg)
{}

const char	*Exception::what() const throw()
{
  return (_error.c_str());
}
