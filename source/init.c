//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/init.c                                                      ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/eternity.h"

none	init_(t_program *c, i_H * title)
{
	c->title = dc_strdup(title);
	c->cursorX = 1;
	c->cursorY = 2;
	c->currentfile = -1;
	getcwd(c->cwd, sizeof(c->cwd));
	list_dir_content(c);

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(REG_FILE_H, COLOR_BLACK, COLOR_GREEN); // highlight file
	init_pair(REG_FILE, COLOR_GREEN, COLOR_BLACK); // file
	init_pair(DIRECTORY_H, COLOR_BLACK, COLOR_RED); // highlight folder
	init_pair(DIRECTORY, COLOR_RED, COLOR_BLACK); // folder
	attron(COLOR_PAIR(REG_FILE));

}