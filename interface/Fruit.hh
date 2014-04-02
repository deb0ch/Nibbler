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
