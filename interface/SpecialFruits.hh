//
// SpecialFruits.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 17:30:58 2014 chauvo_t
// Last update Thu Apr 10 23:19:06 2014 chauvo_t
//

#ifndef		SPECIALFRUITS_H_
# define	SPECIALFRUITS_H_

# include "../interface/ASpecialFruit.hh"

class MaxiFruit : public ASpecialFruit
{
public:
  virtual eType		type() const { return (MAXI_FRUIT); }

public:
  MaxiFruit(int posx, int posy) : ASpecialFruit(posx, posy) { _timer = 30; }
  ~MaxiFruit() {}

private:
  MaxiFruit();
  MaxiFruit(const MaxiFruit &);
  MaxiFruit &operator=(const MaxiFruit &);
};

class SpeedFruit : public ASpecialFruit
{
public:
  virtual eType		type() const { return (SPEED_FRUIT); }

public:
  SpeedFruit(int posx, int posy) : ASpecialFruit(posx, posy) { _timer = 30; }
  ~SpeedFruit() {}

private:
  SpeedFruit();
  SpeedFruit(const SpeedFruit &);
  SpeedFruit &operator=(const MaxiFruit &);
};

class SlowFruit : public ASpecialFruit
{
public:
  virtual eType		type() const { return (SLOW_FRUIT); }

public:
  SlowFruit(int posx, int posy) : ASpecialFruit(posx, posy) { _timer = 30; }
  ~SlowFruit() {}

private:
  SlowFruit();
  SlowFruit(const SlowFruit &);
  SlowFruit &operator=(const SlowFruit &);
};

class ReverseFruit : public ASpecialFruit
{
public:
  virtual eType		type() const { return (REVERSE_FRUIT); }

public:
  ReverseFruit(int posx, int posy) : ASpecialFruit(posx, posy) { _timer = 40; }
  ~ReverseFruit() {}

private:
  ReverseFruit();
  ReverseFruit(const ReverseFruit &);
  ReverseFruit &operator=(const ReverseFruit &);
};

#endif /* !SPECIALFRUITS_H_ */
