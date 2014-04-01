##
## Makefile for corewar_vm in /home/chauvo_t/corewar_2013/vm
##
## Made by Thomas de Beauchene
## Login   <chauvo_t@epitech.net>
##
## Last update Tue Apr  1 22:27:26 2014 chauvo_t
## Last update Sun Dec 15 00:24:02 2013 chauvo_t
##

CXX			:= g++

RM			:= rm -f

DEBUG			:= debug

SRCDIR			:= src

OBJDIR			:= build

HDRDIR			:= include
HDRDIR			+= ../interface

SRCS			:=	Panda.cpp	\
#				other_file.cpp

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

CXXFLAGS		+= -Werror -Wextra -Wall -W
CXXFLAGS		+= $(addprefix "-I./", $(HDRDIR))
CXXFLAGS		+= -O2 -fPIC
$(DEBUG): CXXFLAGS	+= -g3 -ggdb

LDFLAGS			+= -shared #-Wl,--whole-archive
LDFLAGS			+= -lSDLmain -lSDL
$(DEBUG): LDFLAGS	+= -g3 -ggdb

TMPS			:=	$(OBJS)			\
				$(SRCS:.cpp=.cpp~)	\
				Makefile~

NAME			:= ../lib_panda.so


all:		$(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
		$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJS):	| $(OBJDIR)

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
	@$(RM) $(TMPS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
