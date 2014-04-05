//
// FruitFactory.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 23:29:54 2014 chauvo_t
// Last update Sat Apr  5 14:51:13 2014 chauvo_t
//

#include "../include/FruitFactory.hh"

// Public

FruitFactory	*FruitFactory::getInstance()
{
  if (_fruitFactory == NULL)
    _fruitFactory = new FruitFactory;
  return (_fruitFactory);
}

void	FruitFactory::deleteInstance()
{
  if (_fruitFactory != NULL)
    {
      delete (_fruitFactory);
      _fruitFactory = NULL;
    }
}

Fruit	*FruitFactory::createFruit(AItem::eType type, int posx, int posy)
{
  if (_createFruit.count(type))
    return ((this->*_createFruit[type])(posx, posy));
  else
    throw Exception("Invalid fruit asked to factory");
}

// Private

FruitFactory::FruitFactory()
{
  this->_createFruit[AItem::FRUIT] = &FruitFactory::createBasicFruit;
  // Fill the map here with your creation functions
}

Fruit*	FruitFactory::createBasicFruit(int posx, int posy) const
{
  return (new Fruit(posx, posy));
}
