//
// FruitFactory.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 23:29:54 2014 chauvo_t
// Last update Fri Apr  4 00:30:30 2014 chauvo_t
//

#include "../include/FruitFactory.hh"

FruitFactory::FruitFactory()
{
  this->_createFruit[AItem::FRUIT]	= &FruitFactory::createFruit;
}

FruitFactory		*FruitFactory::getInstance()
{
  if (_fruitFactory == NULL)
    _fruitFactory = new FruitFactory;
  return (_fruitFactory);
}

void			FruitFactory::deleteInstance()
{
  if (_fruitFactory != NULL)
    {
      delete (_fruitFactory);
      _fruitFactory = NULL;
    }
}

Fruit		*FruitFactory::createFruit(AItem::eType type, int posx, int posy)
{
  if (this->_createFruit[type])
    return ((this->*_createFruit[type])(posx, posy));
  else
    throw Exception("Invalid fruit asked to factory");
}
