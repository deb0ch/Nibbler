//
// Message.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 13:05:15 2014 chauvo_t
// Last update Wed Apr  2 13:54:00 2014 chauvo_t
//

#include "../../interface/Message.hh"

Message::Message(const std::string & msg)
  : _msg(msg)
{}

const std::string &	Message::str() const
{
  return _msg;
}
