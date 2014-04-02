#include <iostream>
#include "../include/Koala.hh"
#include "../../interface/Message.hh"

//Implementation of method talk()
void Koala::talk(const Message & msg) const
{
  std::cout << "Koala says KREOOOOOOOOOOG !" << msg.str() << std::endl;
}

//Function to create a Koala
//Will be called from code to get a Koala instance

extern "C"
{
  IAssistant* create_assistant()
  {
    return new Koala();
  }
}
