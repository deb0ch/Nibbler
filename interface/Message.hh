//
// Message.hh for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 13:07:10 2014 chauvo_t
// Last update Wed Apr  2 13:21:51 2014 chauvo_t
//

#ifndef		MESSAGE_H_
# define	MESSAGE_H_

# include <string>

class Message
{
  private:
  std::string	_msg;

  public:
  Message(const std::string & msg);
  const std::string &	str() const;
};

#endif /* !MESSAGE_H_ */
