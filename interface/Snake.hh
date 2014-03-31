//
// Snake.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:30:43 2014 chauvo_t
// Last update Wed Apr  2 17:35:25 2014 chauvo_t
//

#ifndef		SNAKE_H_
# define	SNAKE_H_

# include <list>
# include "SnakeRing.hh"

class Snake
{
public:
  Snake();
  virtual ~Snake();

private:
  Snake(const Snake &);
  Snake &operator=(const Snake &);

private:
  std::list<SnakeRing>	rings;
};

#endif /* !SNAKE_H_ */
