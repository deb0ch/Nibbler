//
// FruitFactory.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 23:29:44 2014 chauvo_t
// Last update Fri Apr  4 23:21:02 2014 chauvo_t
//

#ifndef		FRUITFACTORY_HH_
# define	FRUITFACTORY_HH_

# include <map>
# include <cstdlib>
# include "../include/Exception.hh"
# include "../../interface/Fruit.hh"

class	FruitFactory
{
public:
  static FruitFactory		*getInstance();
  static void			deleteInstance();
  Fruit				*createFruit(AItem::eType type, int posx, int posy);

private:
  FruitFactory();
  FruitFactory(const FruitFactory&);
  FruitFactory			&operator=(const FruitFactory&);
  ~FruitFactory() {}

private:
  typedef Fruit			*(FruitFactory::*create)(int posx, int posy) const;
  std::map<AItem::eType, create> _createFruit;
  static FruitFactory		*_fruitFactory;

private:
  Fruit				*createBasicFruit(int posx, int posy) const;
};

#endif /* !FRUITFACTORY_HH_ */
