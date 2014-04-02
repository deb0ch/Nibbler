#ifndef		CORE_H_
# define	CORE_H_

# include <string>
# include "../../interface/Game.hh"

class Core
{
public:
  Core(std::string lib_path, int width, int height);
  void	openLib();
  void	gameLoop();
  void	closeLib();
  virtual ~Core();

private:
  Core(const Core &);
  Core &operator=(const Core &);

private:
  Game	game;
};

#endif /* !CORE_H_ */
