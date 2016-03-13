# Nibbler

A snake-like game for Linux. Eat fruits, grow your snake, max your score but don't crash into a wall !

The graphics display is coded as a plug-in system: a shared library (.so) is given as argument to the program on launch.

There are currently 3 graphical displays: using ncurses, SDL and OpenGL.

Only ncurses display implements the score and special fruits at the moment.

Usage:

$> ./nibbler 25 20 ./lib_nibbler_ncurses.so ./lib_nibbler_sdl.so ./lib_nibbler_opengl.so

Keys:

Left: left
Right: right
Pause/continue: p
switch displays: 0
