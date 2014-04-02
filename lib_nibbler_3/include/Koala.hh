#ifndef __KOALA_HH__
# define __KOALA_HH__

# include "../../interface/IAssistant.hh" //Must include the interface from core

class Koala : public IAssistant
{
public:
  virtual void talk(const Message & msg) const;
};

#endif
