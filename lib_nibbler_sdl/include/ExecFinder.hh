//
// ExecFinder.hh for zappy in /home/ubuntu/rendu/zappy-zappo/client_graph/utility
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Jun 12 09:20:54 2014 chauvo_t
// Last update Sun Dec 21 15:51:18 2014 chauvo_t
//

#ifndef EXECFINDER_H_
# define EXECFINDER_H_

# include <string>
# include "Exception.hh"

class ExecFinder
{
public:
  const std::string &	operator()();

public:
  ExecFinder();
  ~ExecFinder();

private:
  ExecFinder(const ExecFinder &);
  ExecFinder &operator=(const ExecFinder &);

private:
  std::string		_path;
};

#endif /* !EXECFINDER_H_ */
