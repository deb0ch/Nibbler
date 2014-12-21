//
// DlLoader.hh for nibbler in /home/ubuntu/perso/nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Mon Apr  7 20:29:44 2014 chauvo_t
// Last update Mon Apr  7 22:06:39 2014 chauvo_t
//

#ifndef		DLLOADER_H_
# define	DLLOADER_H_

# include <dlfcn.h>
# include <iostream>
# include <string>
# include <vector>
# include "../../interface/Exception.hh"
# include "../../interface/IDisplay.hh"

class DlLoader
{
public:
  void			openLib(const GameBoard & game);
  void			switchLib(const GameBoard & game);
  void			closeLib();
  IDisplay*		getDisplay() const;

public:
  DlLoader(const std::vector<std::string> & libs);
  ~DlLoader();

private:
  DlLoader();
  DlLoader(const DlLoader &);
  DlLoader&		operator=(const DlLoader &);

private:
  std::vector<std::string>			_libs;
  std::vector<std::string>::iterator		_libsIt;
  void						*_libHandle;
  IDisplay					*_display;

private:
  void			tryOpenLib(const GameBoard & game);

};

#endif /* !DLLOADER_H_ */
