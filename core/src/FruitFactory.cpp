//
// FruitFactory.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 23:29:54 2014 chauvo_t
// Last update Thu Apr 10 23:19:40 2014 chauvo_t
//

#include "../include/FruitFactory.hh"

// Public

Fruit*	FruitFactory::createFruit(AItem::eType type, int posx, int posy)
{
  if (_createFruit.count(type))
    return ((this->*_createFruit[type])(posx, posy));
  else
    throw Exception("Invalid fruit asked to factory");
}

Fruit*	FruitFactory::createRandomFruit(int posx, int posy)
{
  return (this->createFruit(static_cast<AItem::eType>
			    (_randomizer.rangeRand(AItem::MAXI_FRUIT, AItem::REVERSE_FRUIT)),
			    posx, posy));
}

FruitFactory::FruitFactory()
{
  _createFruit[AItem::BASIC_FRUIT] = &FruitFactory::createBasicFruit;
  _createFruit[AItem::MAXI_FRUIT] = &FruitFactory::createMaxiFruit;
  _createFruit[AItem::SPEED_FRUIT] = &FruitFactory::createSpeedFruit;
  _createFruit[AItem::SLOW_FRUIT] = &FruitFactory::createSlowFruit;
  _createFruit[AItem::REVERSE_FRUIT] = &FruitFactory::createReverseFruit;
  _specialFruitsFreq[AItem::BASIC_FRUIT] = 0;
  _specialFruitsFreq[AItem::MAXI_FRUIT] = 40;
  _specialFruitsFreq[AItem::SPEED_FRUIT] = 200;
  _specialFruitsFreq[AItem::SLOW_FRUIT] = 200;
  _specialFruitsFreq[AItem::REVERSE_FRUIT] = 100;
  _sumFreqs = 0;
  for (int i = AItem::BASIC_FRUIT; i < AItem::TYPE_LAST; ++i)
    _sumFreqs += _specialFruitsFreq[i];
}

// Private

Fruit*	FruitFactory::createBasicFruit(int posx, int posy) const
{
  return (new Fruit(posx, posy));
}

Fruit*	FruitFactory::createMaxiFruit(int posx, int posy) const
{
  return (new MaxiFruit(posx, posy));
}

Fruit*	FruitFactory::createSpeedFruit(int posx, int posy) const
{
  return (new SpeedFruit(posx, posy));
}

Fruit*	FruitFactory::createSlowFruit(int posx, int posy) const
{
  return (new SlowFruit(posx, posy));
}

Fruit*	FruitFactory::createReverseFruit(int posx, int posy) const
{
  return (new ReverseFruit(posx, posy));
}
