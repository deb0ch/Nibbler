##
## Makefile for nibbler in /home/ubuntu/rendu/cpp_nibbler
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Tue Apr  1 21:13:58 2014 chauvo_t
## Last update Wed Apr  2 14:09:45 2014 chauvo_t
##

CORE_PATH	:= ./core
LIB_SDL_PATH	:= ./lib_nibbler_sdl
LIB_NC_PATH	:= ./lib_nibbler_ncurses
LIB_3_PATH	:= ./lib_nibbler_3

all:	core lib_sdl lib_ncurses lib_3

debug:
	make debug -C $(CORE_PATH)
	@echo ""
	make debug -C $(LIB_SDL_PATH)
	@echo ""
	make debug -C $(LIB_NC_PATH)
	@echo ""
	make debug -C $(LIB_3_PATH)

core:
	make -C $(CORE_PATH)
	@echo ""

lib_sdl:
	make -C $(LIB_SDL_PATH)
	@echo ""

lib_ncurses:
	make -C $(LIB_NC_PATH)
	@echo ""

lib_3:
	make -C $(LIB_3_PATH)

clean:
	make clean -C $(CORE_PATH)
	@echo ""
	make clean -C $(LIB_SDL_PATH)
	@echo ""
	make clean -C $(LIB_NC_PATH)
	@echo ""
	make clean -C $(LIB_3_PATH)

fclean:
	make fclean -C $(CORE_PATH)
	@echo ""
	make fclean -C $(LIB_SDL_PATH)
	@echo ""
	make fclean -C $(LIB_NC_PATH)
	@echo ""
	make fclean -C $(LIB_3_PATH)

re:
	make re -C $(CORE_PATH)
	@echo ""
	make re -C $(LIB_SDL_PATH)
	@echo ""
	make re -C $(LIB_NC_PATH)
	@echo ""
	make re -C $(LIB_3_PATH)

.PHONY: all core lib_sdl lib_ncurses lib_3 clean fclean re
