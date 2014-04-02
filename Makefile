##
## Makefile for nibbler in /home/ubuntu/rendu/cpp_nibbler
##
## Made by chauvo_t
## Login   <chauvo_t@epitech.net>
##
## Started on  Tue Apr  1 21:13:58 2014 chauvo_t
## Last update Wed Apr  2 11:39:48 2014 chauvo_t
##

CORE_PATH	:= ./core
LIB_SDL_PATH	:= ./lib_nibbler_sdl
LIB_2_PATH	:= ./lib_nibbler_2
LIB_3_PATH	:= ./lib_nibbler_3

all:	core lib_sdl lib_2 lib_3

debug:
	make debug -C $(CORE_PATH)
	@echo ""
	make debug -C $(LIB_SDL_PATH)
	@echo ""
	make debug -C $(LIB_2_PATH)
	@echo ""
	make debug -C $(LIB_3_PATH)

core:
	make -C $(CORE_PATH)
	@echo ""

lib_sdl:
	make -C $(LIB_SDL_PATH)
	@echo ""

lib_2:
	make -C $(LIB_2_PATH)
	@echo ""

lib_3:
	make -C $(LIB_3_PATH)

clean:
	make clean -C $(CORE_PATH)
	@echo ""
	make clean -C $(LIB_SDL_PATH)
	@echo ""
	make clean -C $(LIB_2_PATH)
	@echo ""
	make clean -C $(LIB_3_PATH)

fclean:
	make fclean -C $(CORE_PATH)
	@echo ""
	make fclean -C $(LIB_SDL_PATH)
	@echo ""
	make fclean -C $(LIB_2_PATH)
	@echo ""
	make fclean -C $(LIB_3_PATH)

re:
	make re -C $(CORE_PATH)
	@echo ""
	make re -C $(LIB_SDL_PATH)
	@echo ""
	make re -C $(LIB_2_PATH)
	@echo ""
	make re -C $(LIB_3_PATH)

.PHONY: all core lib_sdl lib_2 lib_3 clean fclean re
