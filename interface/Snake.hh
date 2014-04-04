//
// Snake.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:30:43 2014 chauvo_t
// Last update Fri Apr  4 16:29:12 2014 chauvo_t
//

#ifndef		SNAKE_H_
# define	SNAKE_H_

# include <list>
# include "SnakeRing.hh"

class Snake
{
public:
  unsigned int			speed() const;
  void				setSpeed(unsigned int speed);

public:
  Snake();
  virtual ~Snake() {}

private:
  Snake(const Snake &);
  Snake				&operator=(const Snake &);

private:
  std::list<SnakeRing>		_rings;
  unsigned int			_speed;
};

#endif /* !SNAKE_H_ */
