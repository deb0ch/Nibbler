//
// DlLoader.cpp for nibbler in /home/ubuntu/perso/nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Mon Apr  7 20:52:12 2014 chauvo_t
// Last update Mon Apr  7 22:12:09 2014 chauvo_t
//

#include "../include/DlLoader.hh"

// Public

IDisplay*	DlLoader::getDisplay() const
{
  return (_display);
}

void	DlLoader::openLib(const GameBoard & game)
{
  size_t	i;

  for (i = 0; i < _libs.size(); ++i)
    {
      try
	{
	  if (_libsIt == _libs.end())
	    _libsIt = _libs.begin();
	  this->tryOpenLib(game);
	  break ;
	}
      catch (Exception e)
	{
	  std::cerr << e.what() << std::endl;
	  ++_libsIt;
	  if (_libsIt == _libs.end())
	    _libsIt = _libs.begin();
	  continue ;
	}
      break ;
    }
}

void	DlLoader::switchLib(const GameBoard & game)
{
  this->closeLib();
  ++_libsIt;
  this->openLib(game);
}

void	DlLoader::closeLib()
{
  char*		error;

  _display->close();
  delete _display;
  _display = NULL;
  dlerror();
  dlclose(_libHandle);
  _libHandle = NULL;
  if ((error = dlerror()) != NULL)
    throw Exception("dlclose error closing library: " + std::string(error));
}

DlLoader::DlLoader(const std::vector<std::string> & libs)
  : _libs(libs), _libsIt(_libs.begin()), _libHandle(NULL), _display(NULL)
{}

DlLoader::~DlLoader()
{}

// Private

void	DlLoader::tryOpenLib(const GameBoard & game)
{
  IDisplay*	(*createDisplay)();
  IDisplay*	tmpLib;
  char*		error;

  _libHandle = dlopen((*(_libsIt)).c_str(), RTLD_LAZY);
  if (_libHandle == NULL)
    throw Exception("dlopen error: " + std::string(dlerror()));
  dlerror();
  createDisplay = reinterpret_cast<IDisplay* (*)()>(dlsym(_libHandle, "createDisplay"));
  if ((error = dlerror()) != NULL)
    throw Exception("dlsym error loading library entry point: " + std::string(error));
  tmpLib = createDisplay();
  if (tmpLib->getMaxWidth() < game.width()
      || tmpLib->getMaxHeight() < game.height())
    {
      delete tmpLib;
      dlerror();
      dlclose(_libHandle);
      _libHandle = NULL;
      if ((error = dlerror()) != NULL)
	throw Exception("dlclose error: " + std::string(error) + "\nmap too big for "
			+ *_libsIt);
      throw Exception("map too big for " + *_libsIt);
    }
  _display = tmpLib;
  _display->init(game);
}
