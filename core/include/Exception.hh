//
// Exception.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr  3 10:02:19 2014 chauvo_t
// Last update Sat Apr  5 11:09:40 2014 chauvo_t
//

#ifndef	EXCEPTION_HH_
# define EXCEPTION_HH_

# include <exception>
# include <sstream>
# include <string>

class	Exception : public std::exception
{
private:
  std::string		_error;

public:
  Exception(const std::string& msg);
  virtual		~Exception() throw() {};

public:
  virtual const char	*what() const throw();
};

#endif /* !EXCEPTION_HH_ */
