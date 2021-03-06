//
// SnakeRing.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:35:36 2014 chauvo_t
// Last update Fri Apr 11 00:05:08 2014 chauvo_t
//

#ifndef		SNAKERING_H_
# define	SNAKERING_H_

# include "../interface/AItem.hh"

class SnakeRing : public AItem
{
public:
  typedef enum
    {
      UP = 0,
      RIGHT = 1,
      DOWN = 2,
      LEFT = 3
    } eDirection;

public:
  virtual eType		type() const { return (SNAKE); }
  eDirection		direction() const { return (_direction); }
  void			setDirection(eDirection newDir) { _direction = newDir; }

public:
  SnakeRing(eDirection dir, int posx, int posy) : AItem(posx, posy), _direction(dir) {}
  virtual ~SnakeRing() {}

private:
  SnakeRing();
  SnakeRing(const SnakeRing &);
  SnakeRing &operator=(const SnakeRing &);

private:
  eDirection		_direction;
};

#endif /* !SNAKERING_H_ */
