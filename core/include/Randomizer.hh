//
// Randomizer.hh for nibbler in /home/ubuntu/perso/nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  9 10:51:51 2014 chauvo_t
// Last update Thu Apr 10 00:07:30 2014 chauvo_t
//

#ifndef		RANDOMIZER_H_
# define	RANDOMIZER_H_

# include <cstdlib>
# include <time.h>

class Randomizer
{
public:
  int			rangeRand(int from, int to);
  bool			probaRand(double proba);

public:
  Randomizer();
  ~Randomizer() {}

private:
  Randomizer(const Randomizer &);
  Randomizer&		operator=(const Randomizer &);
};

#endif /* !RANDOMIZER_H_ */
