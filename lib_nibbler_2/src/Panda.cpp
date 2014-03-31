#include <iostream>
#include "../include/Panda.hh"
#include "../../interface/Message.hh"

//Implementation of method talk()
void Panda::talk(const Message & msg) const
{
  std::cout << msg.str() << std::endl;
}

//Function to create a Panda
//Will be called from code to get a Panda instance

extern "C"
{
  IAssistant* create_assistant()
  {
    return new Panda();
  }
}
