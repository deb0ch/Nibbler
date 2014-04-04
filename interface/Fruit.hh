//
// Fruit.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:30:58 2014 chauvo_t
// Last update Sat Apr  5 00:06:36 2014 chauvo_t
//

#ifndef		FRUIT_H_
# define	FRUIT_H_

# include "../interface/AItem.hh"

class Fruit : public AItem
{
public:
  virtual eType		type() const { return (FRUIT); }

public:
  Fruit(int posx, int posy) : AItem(posx, posy) {}
  virtual ~Fruit();

private:
  Fruit();
  Fruit(const Fruit &);
  Fruit &operator=(const Fruit &);

protected:
  int			_posx;
  int			_posy;
};

#endif /* !FRUIT_H_ */
