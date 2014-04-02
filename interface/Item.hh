#ifndef		COORD_H_
# define	COORD_H_

class Item
{
public:
  typedef enum
    {
      WALL,
      SNAKE,
      FRUIT,
      TYPE_LAST
    }		eType;

  Item();
  virtual ~Item();

private:
  Item(const Item &);
  Item &operator=(const Item &);
protected:
  int		posx;
  int		posy;
  eType		type;
};

#endif /* !COORD_H_ */
