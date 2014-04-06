##
## Makefile<3> for nibbler in /home/ubuntu/rendu/cpp_nibbler
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Tue Apr  1 22:16:30 2014 chauvo_t
## Last update Sun Apr  6 15:55:11 2014 chauvo_t
##

CXX			:= g++

RM			:= rm -f

DEBUG			:= debug

SRCDIR			:= src

OBJDIR			:= build

HDRDIR			:= include
HDRDIR			+= ../interface

SRCS			:= openglDisplay.cpp	\

OBJS			:= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
SRCS			:= $(addprefix $(SRCDIR)/, $(SRCS))

DEPS			:= $(OBJS:.o=.d)

CXXFLAGS		+= -Wextra -Wall -W
CXXFLAGS		+= $(addprefix -I./, $(HDRDIR))
CXXFLAGS		+= -O2 -MD
CXXFLAGS		+= -fPIC

$(DEBUG): CXXFLAGS	+= -g3 -ggdb

LDFLAGS			+= -shared #-Wl,-soname,lib_ogl.so
LDFLAGS			+= -lGL -lglut -lGLU
$(DEBUG): LDFLAGS	+= -g3 -ggdb

TMPS			:=	$(OBJS)			\
				$(DEPS)			\
				$(SRCS:.cpp=.cpp~)	\
				Makefile~

NAME			:= ../lib_nibbler_opengl.so


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
