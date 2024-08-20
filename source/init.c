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
	c->fileselected = 0;
	c->offset = 0;
	c->title = dc_strdup(title);
	c->cursorX = 1;
	c->cursorY = 2;
	c->currentfile = -1;
	c->copyfile = NULL;
	c->copyfilename = NULL;
	getcwd(c->cwd, sizeof(c->cwd));
	list_dir_content(c);

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(REG_FILE_H, COLOR_BLACK, COLOR_MAGENTA); // highlight file
	init_pair(REG_FILE, COLOR_MAGENTA, COLOR_BLACK); // file
	init_pair(DIRECTORY_H, COLOR_BLACK, COLOR_CYAN); // highlight folder
	init_pair(DIRECTORY, COLOR_CYAN, COLOR_BLACK); // folder

}