//
// Timer.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 18:21:18 2014 chauvo_t
// Last update Thu Apr  3 16:34:51 2014 chauvo_t
//

#ifndef		TIMER_H_
# define	TIMER_H_

# define _XOPEN_SOURCE 700

# include <errno.h>
# include <exception>
# include <string.h>
# include <time.h>
# include <unistd.h>
# include "Exception.hh"

class Timer
{
public:
  Timer();
  ~Timer();

public:
  unsigned long		getMilliTime();
  void			milliSleep(unsigned long delay) const;

private:
  struct timespec	_timeBuff;
  unsigned long		_milliTimeZero;

private:
  Timer(const Timer &);
  Timer &operator=(const Timer &);

  inline long		bufToMilliTime(const struct timespec & timebuff) const;
};

#endif /* !TIMER_H_ */
