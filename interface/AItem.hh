//
// AItem.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 17:53:45 2014 chauvo_t
// Last update Thu Apr  3 18:00:22 2014 chauvo_t
//

#ifndef		AITEM_H_
# define	AITEM_H_

class AItem
{
public:
  typedef enum
    {
      WALL,
      SNAKE,
      FRUIT,
      TYPE_LAST
    }		eType;

public:
  int			posx() const;
  int			posy() const;
  virtual eType		type() const = 0;

public:
  AItem(int posx, int posy);
  virtual ~AItem();

private:
  AItem(const AItem &);
  AItem			&operator=(const AItem &);

protected:
  int			_posx;
  int			_posy;
};

#endif /* !AITEM_H_ */
