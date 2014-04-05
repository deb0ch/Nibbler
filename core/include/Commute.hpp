//
// Commute.hpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Sat Apr  5 11:34:33 2014 chauvo_t
// Last update Sat Apr  5 11:41:09 2014 chauvo_t
//

# ifndef	COMMUTE_HPP_
# define	COMMUTE_HPP_

# include	<sstream>
# include	<string>
# include	<iostream>

template		<typename T>
T			commute(const std::string &value)
{
  std::istringstream	ss(value);
  T			ret;

  ss >> ret;
  return (ret);
}

# endif		/* !COMMUTE_HPP_ */
