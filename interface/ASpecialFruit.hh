//
// ASpecialFruit.hh for nibbler in /home/ubuntu/perso/nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  9 11:38:24 2014 chauvo_t
// Last update Thu Apr 10 11:49:07 2014 chauvo_t
//

#ifndef		ASPECIALFRUIT_H_
# define	ASPECIALFRUIT_H_

# include "Fruit.hh"

class ASpecialFruit : public Fruit
{
public:
  int			getTimer() const;
  void			setTimer(int time);
  void			tick();

public:
  ASpecialFruit(int posx, int posy) : Fruit(posx, posy), _timer(30) {}
  ~ASpecialFruit() {}

private:
  ASpecialFruit();
  ASpecialFruit(const ASpecialFruit &);
  ASpecialFruit &operator=(const ASpecialFruit &);

protected:
  int			_timer;
};

#endif /* !ASPECIALFRUIT_H_ */
