//
// FruitFactory.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 23:29:44 2014 chauvo_t
// Last update Thu Apr 10 11:00:55 2014 chauvo_t
//

#ifndef		FRUITFACTORY_HH_
# define	FRUITFACTORY_HH_

# include <map>
# include <cstdlib>
# include "../include/Randomizer.hh"
# include "../../interface/Exception.hh"
# include "../../interface/SpecialFruits.hh"
# include "../../interface/Fruit.hh"

class	FruitFactory
{
public:
  Fruit				*createFruit(AItem::eType type, int posx, int posy);
  Fruit				*createRandomFruit(int posx, int posy);

public:
  FruitFactory();
  ~FruitFactory() {}

private:
  FruitFactory(const FruitFactory&);
  FruitFactory			&operator=(const FruitFactory&);

private:
  typedef Fruit			*(FruitFactory::*create)(int posx, int posy) const;
  std::map<AItem::eType, create> _createFruit;
  Randomizer			_randomizer;
  int				_specialFruitsFreq[AItem::TYPE_LAST];
  int				_sumFreqs;

private:
  Fruit				*createBasicFruit(int posx, int posy) const;
  Fruit				*createMaxiFruit(int posx, int posy) const;
  Fruit				*createSpeedFruit(int posx, int posy) const;
  Fruit				*createSlowFruit(int posx, int posy) const;
  Fruit				*createReverseFruit(int posx, int posy) const;
};

#endif /* !FRUITFACTORY_HH_ */
