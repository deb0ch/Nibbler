#ifndef		FRUIT_H_
# define	FRUIT_H_

# include "coord.hh"

class Fruit
{
public:
  Fruit();
  virtual ~Fruit();

private:
  Fruit(const Fruit &);
  Fruit &operator=(const Fruit &);

private:
  t_coord	position;

};

#endif /* !FRUIT_H_ */
