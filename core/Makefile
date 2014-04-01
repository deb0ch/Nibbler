##
## Makefile for nibbler in /home/ubuntu/rendu/cpp_nibbler
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Tue Apr  1 10:16:12 2014 chauvo_t
## Last update Tue Apr  1 22:21:26 2014 chauvo_t
##

CXX			:= g++

RM			:= rm -f

DEBUG			:= debug

SRCDIR			:= src

OBJDIR			:= build

HDRDIR			:= include
HDRDIR			+= ../interface

SRCS			:=	main.cpp		\
				# other_file.cpp

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

CXXFLAGS		+= -Werror -Wextra -Wall -W
CXXFLAGS		+= $(addprefix "-I./", $(HDRDIR))
CXXFLAGS		+= -O2
$(DEBUG): CXXFLAGS	+= -g3 -ggdb

LDFLAGS			+= -rdynamic -ldl -lrt
$(DEBUG): LDFLAGS	+= -g3 -ggdb

TMPS			:=	$(OBJS)			\
				$(SRCS:.cpp=.cpp~)	\
				Makefile~

NAME			:= ../nibbler


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