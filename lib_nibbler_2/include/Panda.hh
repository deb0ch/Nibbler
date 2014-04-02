#ifndef __PANDA_HH__
# define __PANDA_HH__

# include "../../interface/IAssistant.hh" // Must include the interface from core

class Panda : public IAssistant
{
public:
  virtual void talk(const Message & msg) const;
};

#endif
