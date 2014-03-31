//
// Fruit.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:30:58 2014 chauvo_t
// Last update Wed Apr  2 17:30:59 2014 chauvo_t
//

#ifndef		FRUIT_H_
# define	FRUIT_H_

# include "Item.hh"

class Fruit : public Item
{
public:
  Fruit();
  virtual ~Fruit();

private:
  Fruit(const Fruit &);
  Fruit &operator=(const Fruit &);

private:

};

#endif /* !FRUIT_H_ */
