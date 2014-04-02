#ifndef		CORE_H_
# define	CORE_H_

#include <string>

class Core
{
public:
  Core(std::string lib_path, int width, int height);
  openLib();
  gameLoop();
  closeLib();
  virtual ~Core();

private:
  Core(const Core &);
  Core &operator=(const Core &);
protected:

};

#endif /* !CORE_H_ */
