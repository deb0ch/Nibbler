##
## Makefile for nibbler in /home/ubuntu/rendu/cpp_nibbler
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Tue Apr  1 10:16:12 2014 chauvo_t
## Last update Thu Apr  3 17:52:16 2014 bourge_i
##

CXX			:= clang++

RM			:= rm -f

DEBUG			:= debug

SRCDIR			:= src

OBJDIR			:= build

HDRDIR			:= include
HDRDIR			+= ../interface

SRCS			:=	main.cpp		\
				Core.cpp  		\
				Exception.cpp		\
				Fruit.cpp		\
				FruitFactory.cpp	\
				GameBoard.cpp		\
				Snake.cpp		\
				Timer.cpp

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

DEPS			:= $(OBJS:.o=.d)

CXXFLAGS		+= -Wextra -Wall -W
CXXFLAGS		+= $(addprefix -I./, $(HDRDIR))
CXXFLAGS		+= -O2 -MD
$(DEBUG): CXXFLAGS	+= -g3 -ggdb

LDFLAGS			+= -rdynamic -ldl -lrt
$(DEBUG): LDFLAGS	+= -g3 -ggdb

TMPS			:=	$(OBJS)			\
				$(OBJS:.o=.d)		\
				$(SRCS:.cpp=.cpp~)	\
				Makefile~

NAME			:= ../nibbler


all:		$(NAME)

$(DEBUG):	fclean $(NAME)

-include $(DEPS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
		$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS):	| $(OBJDIR)

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
	@$(RM) $(TMPS)
	@echo "Object files cleaned"

fclean:	clean
	@$(RM) $(NAME)
	@echo "Executable cleaned"

re:	fclean all

.PHONY:	all clean fclean re
