//
// SnakeRing.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:35:36 2014 chauvo_t
// Last update Wed Apr  2 17:36:05 2014 chauvo_t
//

#ifndef		SNAKERING_H_
# define	SNAKERING_H_

# include	"Item.hh"

class SnakeRing : public Item
{
public:
  SnakeRing();
  virtual ~SnakeRing();

private:
  SnakeRing(const SnakeRing &);
  SnakeRing &operator=(const SnakeRing &);
protected:

};

#endif /* !SNAKERING_H_ */
