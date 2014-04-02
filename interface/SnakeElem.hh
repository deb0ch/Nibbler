#ifndef		SNAKEELEM_H_
# define	SNAKEELEM_H_

# include	"Item.hh"

class SnakeElem : public Item
{
public:
  SnakeElem();
  virtual ~SnakeElem();

private:
  SnakeElem(const SnakeElem &);
  SnakeElem &operator=(const SnakeElem &);
protected:

};

#endif /* !SNAKEELEM_H_ */
