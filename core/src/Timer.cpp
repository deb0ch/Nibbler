//
// Timer.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 18:23:43 2014 chauvo_t
// Last update Fri Apr 11 22:47:54 2014 chauvo_t
//

#include <iostream>
#include "../include/Timer.hh"

// Public:

Timer::Timer()
{
  if (clock_gettime(CLOCK_MONOTONIC, &_timeBuff) == -1)
    throw Exception("clock_gettime error during Timer construction: "
		    + std::string(strerror(errno)));
  _milliTimeZero = bufToMilliTime(_timeBuff);
}

unsigned long	Timer::getMilliTime()
{
  if (clock_gettime(CLOCK_MONOTONIC, &_timeBuff) == -1)
    throw Exception("clock_gettime error: " + std::string(strerror(errno)));
  return (bufToMilliTime(_timeBuff) - _milliTimeZero);
}

void		Timer::milliSleep(unsigned long delay) const
{
  // std::cerr << delay * 1000 << std::endl;
  if (usleep(delay * 1000) == -1)
    throw Exception("usleep error: " + std::string(strerror(errno)));
}

// Private:

inline long	Timer::bufToMilliTime(const struct timespec & timeBuff) const
{
  return (timeBuff.tv_sec * 1000 + timeBuff.tv_nsec / 1000000);
}
