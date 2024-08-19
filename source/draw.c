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

none draw_panes(t_program *c)
{
	i_P i;
	i_P q;
	i_P	pane;

	c->fileselected = 0;
	pane = 1;
	q = 0;
	i = 2;
	while (q < c->filecount)
	{
		if (c->cursorY == i && c->file_entries[q + c->offset].type == REG_FILE && c->cursorX == pane)
		{
			attron(COLOR_PAIR(REG_FILE_H));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q + c->offset].name);
			mvprintw(33, 2, "%s", c->file_entries[q + c->offset].name);
			c->currentfile = q + c->offset;
			mvprintw(38, 0, "%d", c->currentfile);
			c->fileselected = 1;
		} 
		else if(c->cursorY == i && c->file_entries[q + c->offset].type == DIRECTORY && c->cursorX == pane)
		{
			attron(COLOR_PAIR(DIRECTORY_H));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q + c->offset].name);
			mvprintw(33, 2, "%s", c->file_entries[q + c->offset].name);
			c->currentfile = q + c->offset;
			mvprintw(38, 0, "%d", c->currentfile);
			c->fileselected = 1;
		}
		else if (c->file_entries[q + c->offset].type == REG_FILE)
		{
			attron(COLOR_PAIR(REG_FILE));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q + c->offset].name);
		} 
		else if (c->file_entries[q + c->offset].type == DIRECTORY)
		{
			attron(COLOR_PAIR(DIRECTORY));
			mvprintw(i, pane + 1, "%.30s", c->file_entries[q + c->offset].name);
		}
		mvprintw(0, 0, "%d", c->fileselected);
		i++;
		q++;
		if (i == P_1)
		{
			i = 2;
			pane += P_1;
		}
		if (pane > 66)
			pane = 2;

		
		if (q + c->offset == c->filecount || q == 90)
			break ;
	}
}

none	draw_(t_program *c)
{
	
	attron(COLOR_PAIR(REG_FILE));
	mvprintw(0, P_2, "CTRL_Y - bash");
	mvprintw(0, P_1, "%s", c->title);
	i_P	i;

	i = 0;
	
	while (i <= P_3)
	{
		mvprintw(_A, i, "-");
		i++;
	}
	i = 2;
	while (i < P_1)
	{
		mvprintw(i, P_0, "|");
		mvprintw(i, P_1, "|");
		mvprintw(i, P_2, "|");
		mvprintw(i, P_3, "|");
	
		i++;
	}
	i = 0;
	while (i <= 96)
	{
		mvprintw(P_1, i, "-");
		i++;
	}
	i = 33;
	while (i < 38)
	{
		mvprintw(i, P_0, "|");
		mvprintw(i, P_1, "|");
		mvprintw(i, P_2, "|");
		mvprintw(i, P_3, "|");
	
		i++;
	}
	mvprintw(34, 2, "Enter    - Use File");
	mvprintw(35, 2, "CTRL_DEL - Remove File/Folder");
	mvprintw(36, 2, "CTRL_I   - Insert File");

	mvprintw(34, 34, "CTRL_R   - Run Program");
	
	mvprintw(36, 34, "CTRL_R   - Insert Folder");

	mvprintw(36, 66, "PgDn     - Next Pane");	
	mvprintw(34, 66, "PgUp     - Prev Pane");

	i = 0;
	while (i <= 96)
	{
		mvprintw(37, i, "-");
		i++;
	}
	mvprintw(38, 2, "%s", c->cwd);

	draw_panes(c);
	
}



