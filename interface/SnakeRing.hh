//
// SnakeRing.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:35:36 2014 chauvo_t
// Last update Sat Apr  5 14:34:09 2014 chauvo_t
//

#ifndef		SNAKERING_H_
# define	SNAKERING_H_

# include "../interface/AItem.hh"

class SnakeRing : public AItem
{
public:
  virtual eType		type() const { return (SNAKE); }

public:
  SnakeRing(int posx, int posy) : AItem(posx, posy) {}
  virtual ~SnakeRing();

private:
  SnakeRing();
  SnakeRing(const SnakeRing &);
  SnakeRing &operator=(const SnakeRing &);
};

#endif /* !SNAKERING_H_ */
