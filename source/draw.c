//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/draw.c                                                      ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/eternity.h"

none draw_list_box_1(t_program *c)
{
	i_P i;

	i = 2;
	while (i < 32)
	{
		if (c->cursorY == i && c->cursorX < 34 && c->file_entries[i].type == REG_FILE)
		{
			attron(COLOR_PAIR(REG_FILE_H));
			mvprintw(i, 2, "%s", c->file_entries[i].name);
			attroff(COLOR_PAIR(REG_FILE_H));
		} else if(c->cursorY == i && c->cursorX < 34 && c->file_entries[i].type == DIRECTORY)
		{
			attron(COLOR_PAIR(DIRECTORY_H));
			mvprintw(i, 2, "%s", c->file_entries[i].name);
			attroff(COLOR_PAIR(DIRECTORY_H));
		} else if (c->cursorY != i && c->cursorX < 34 && c->file_entries[i].type == REG_FILE)
		{
			attron(COLOR_PAIR(REG_FILE));
			mvprintw(i, 2, "%s", c->file_entries[i].name);
			attroff(COLOR_PAIR(REG_FILE));
		} else if (c->cursorY != i && c->cursorX < 34 && c->file_entries[i].type == DIRECTORY)
		{
			attron(COLOR_PAIR(DIRECTORY));
			mvprintw(i, 2, "%s", c->file_entries[i].name);
			attroff(COLOR_PAIR(DIRECTORY));
		} else { mvprintw(i, 2, "%s", c->file_entries[i].name); }
		i++;
		if (i == c->filecount)
			break ;
	}
}

none	draw_(t_program *c)
{
	
	attron(COLOR_PAIR(REG_FILE));
	mvprintw(0, 32, "%s", c->title);
	i_P	i;

	i = 0;
	
	while (i <= 96)
	{
		mvprintw(1, i, "-");
		i++;
	}
	i = 2;
	while (i < 32)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, 32, "|");
		mvprintw(i, 64, "|");
		mvprintw(i, 96, "|");
	
		i++;
	}
	i = 0;
	while (i <= 96)
	{
		mvprintw(32, i, "-");
		i++;
	}

	draw_list_box_1(c);
	
}



