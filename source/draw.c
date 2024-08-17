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
	iP_1 q;
	i_P	pane;

	pane = 1;
	q = 0;
	i = 2;
	while (q < 90)
	{
		if (c->cursorY == i && c->file_entries[q].type == REG_FILE && c->cursorX == pane)
		{
			attron(COLOR_PAIR(REG_FILE_H));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q].name);
			mvprintw(33, 2, "%s", c->file_entries[q].name);
			c->currentfile = q;
			// attroff(COLOR_PAIR(REG_FILE_H));
		} 
		else if(c->cursorY == i && c->file_entries[q].type == DIRECTORY && c->cursorX == pane)
		{
			attron(COLOR_PAIR(DIRECTORY_H));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q].name);
			mvprintw(33, 2, "%s", c->file_entries[q].name);
			c->currentfile = q;
			// attroff(COLOR_PAIR(DIRECTORY_H));
		}
		else if (c->cursorY != i && c->file_entries[q].type == REG_FILE)
		{
			attron(COLOR_PAIR(REG_FILE));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q].name);
			// attroff(COLOR_PAIR(REG_FILE));
		} 
		else if (c->cursorY != i && c->file_entries[q].type == DIRECTORY)
		{
			attron(COLOR_PAIR(DIRECTORY));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q].name);
			// attroff(COLOR_PAIR(DIRECTORY));
		} else { mvprintw(i, pane + 1, "%.30s", c->file_entries[q].name); }
		i++;
		q++;
		if (i == 32)
		{
			i = 2;
			pane += 32;
		}
		if (pane > 66)
			pane = 2;
		if (q == c->filecount || q == 90)
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
	mvprintw(34, 66, "PgDn - Next Pane");
	mvprintw(35, 66, "Entr - Use File");
	mvprintw(34, 2, "PgUp - Prev Pane");

	draw_list_box_1(c);
	
}



