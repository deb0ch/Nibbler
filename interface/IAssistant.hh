#ifndef IASSISTANT_HH__
# define IASSISTANT_HH__

# include "Message.hh"

class IAssistant
{
public:
  virtual void talk(const Message & msg) const = 0;
};

#endif
