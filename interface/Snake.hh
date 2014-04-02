#ifndef		SNAKE_H_
# define	SNAKE_H_

# include <list>
# include "coord.hh"

class Snake
{
public:
  Snake();
  virtual ~Snake();

private:
  Snake(const Snake &);
  Snake &operator=(const Snake &);

private:
  std::list<t_coord>	positions;

};

#endif /* !SNAKE_H_ */
