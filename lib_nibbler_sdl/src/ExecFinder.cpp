//
// ExecutableFinder.cpp for zappy in /home/ubuntu/rendu/zappy-zappo/client_graph/utility
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Jun 12 09:22:07 2014 chauvo_t
// Last update Sun Dec 21 15:50:06 2014 chauvo_t
//

#ifdef _WIN32

# include <Windows.h>

#elif __linux__

# define _XOPEN_SOURCE 500
# include <unistd.h>

#endif /* !__linux__ */

#include "ExecFinder.hh"

// Public

#ifdef _WIN32
# define BUFFSIZE 1024

const std::string &	ExecFinder::operator()()
{
  if (_path == "")
  {
    char	buf[BUFFSIZE];
    int		ret;

    if ((ret = GetModuleFileName(NULL, buf, BUFFSIZE - 1)) == 0)
      throw Exception("readlink error");
    buf[ret] = '\0';
    _path = buf;
    _path = _path.substr(0, _path.rfind('/') + 1);
  }
  return (_path);
}
#elif __linux__
# define BUFFSIZE 1024

const std::string &	ExecFinder::operator()()
{
  if (_path == "")
  {
    char	buf[BUFFSIZE];
    int		ret;

    if ((ret = readlink("/proc/self/exe", buf, BUFFSIZE - 1)) == -1)
      throw Exception("readlink error");
    buf[ret] = '\0';
    _path = buf;
    _path = _path.substr(0, _path.rfind('/') + 1);
  }
  return (_path);
}
#endif /* !__linux__ */

ExecFinder::ExecFinder()
  : _path("")
{}

ExecFinder::~ExecFinder() {}

// Private
