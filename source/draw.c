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
		if (c->cursorY == i && c->cursorX < 34)
		{
			attron(COLOR_PAIR(1));
			mvprintw(i, 2, "%s", c->file_entries[i].name);
			attroff(COLOR_PAIR(1));
		} else { mvprintw(i, 2, "%s", c->file_entries[i].name); }
		
		i++;
		if (i == c->filecount)
			break ;
	}
}

none	draw_(t_program *c)
{
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



