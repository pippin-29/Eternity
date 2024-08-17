//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/control.c                                                   ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Sat Aug 17 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//


#include "../includes/eternity.h"

none run_(t_program *c)
{

here:
	clear();
	draw_(c);
	move(c->cursorY, c->cursorX);
	refresh();

	switch (c->in = getch())
	{
		case(CTRL_q): // quit
			clear();
			break ;
		
		case(CTRL_DEL):
			if (c->file_entries[c->currentfile].type == REG_FILE)
			{
				c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
				remove(c->usefile); 
				free(c->usefile);
				list_dir_content(c);
			} 
			// else if (c->file_entries[c->currentfile].type == DIRECTORY)
			// {
			// 	c->usefile = dc_strjoin_e(4, c->cwd, "/", c->file_entries[c->currentfile].name, "/");
			// 	rmdir(c->usefile); 
			// 	free(c->usefile);
			// 	list_dir_content(c);
			// }
			goto here;

		case('\n'): // Use File or Folder
			if (c->file_entries[c->currentfile].type == REG_FILE)
			{
				endwin();
				c->usefile = dc_strjoin_e(5, "nano", " ", c->cwd, "/", c->file_entries[c->currentfile].name);
				system(c->usefile); free(c->usefile);
				initscr();
				keypad(stdscr, TRUE);				
			} 
			else if (c->file_entries[c->currentfile].type == DIRECTORY)
			{
				c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
				chdir(c->usefile);
				free(c->usefile);
				getcwd(c->cwd, 1024);
				list_dir_content(c);
			}
			goto here;

		case (KEY_RIGHT): // move cursor
			if (c->cursorX < 65)
				c->cursorX += 32;
			goto here;

		case (KEY_LEFT): // move cursor
			if (c->cursorX > 2)
				c->cursorX -= 32;
			goto here;

		case (KEY_UP): // move cursor
			if (c->cursorY > 2)
				c->cursorY--;
			goto here;

		case (KEY_DOWN): // move cursor
			if (c->cursorY < 31)
				c->cursorY++;
			goto here;
		default:
			goto here;
	}
	cleanup(c); // endwin
}