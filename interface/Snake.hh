#ifndef		SNAKE_H_
# define	SNAKE_H_

# include <list>
# include "SnakeElem.hh"

class Snake
{
public:
  Snake();
  virtual ~Snake();

private:
  Snake(const Snake &);
  Snake &operator=(const Snake &);

private:
  std::list<SnakeElem>	bodyParts;

#endif /* !SNAKE_H_ */
