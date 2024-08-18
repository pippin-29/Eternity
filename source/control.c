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
		case (CTRL_y): // yosh.i shell
			endwin();
			system("./pkg/yosh.i");
			initscr();
			keypad(stdscr, TRUE);
			list_dir_content(c);
			goto here ;

		case(CTRL_q): // quit
			clear();
			break ;

		case(CTRL_r): // run program
			if (c->file_entries[c->currentfile].type == REG_FILE && c->fileselected == 1)
			{
				c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
				endwin();
				system(c->usefile);
				free(c->usefile);
				initscr();
				keypad(stdscr, TRUE);				
				list_dir_content(c);
			}
			goto here;
		
		case(KEY_NPAGE):
			if ((c->offset + PANE_SIZE) < c->filecount)
				c->offset += PANE_SIZE;
			goto here;

		case(KEY_PPAGE):
			if (c->offset >= PANE_SIZE)
				c->offset -= PANE_SIZE;
			goto here;

		case(CTRL_DEL):
			if (c->file_entries[c->currentfile].type == REG_FILE && c->fileselected == 1)
			{
				c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
				remove(c->usefile); 
				free(c->usefile);
				list_dir_content(c);
			}
			else if (c->file_entries[c->currentfile].type == DIRECTORY && c->fileselected == 1)
			{
				c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
				rmdir(c->usefile); 
				free(c->usefile);
				list_dir_content(c);
			}
			goto here;

		case(CTRL_i): // inserts file
			endwin();
			system("nano");
			initscr();
			keypad(stdscr, TRUE);
			list_dir_content(c);
			goto here;	

		case('\n'): // Use File or Folder
			if (c->file_entries[c->currentfile].type == REG_FILE && c->fileselected == 1)
			{
				endwin();
				c->usefile = dc_strjoin_e(5, "nano", " ", c->cwd, "/", c->file_entries[c->currentfile].name);
				system(c->usefile); free(c->usefile);
				initscr();
				keypad(stdscr, TRUE);
				list_dir_content(c);				
			} 
			else if (c->file_entries[c->currentfile].type == DIRECTORY && c->fileselected == 1)
			{
				c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
				chdir(c->usefile);
				free(c->usefile);
				getcwd(c->cwd, 1024);
				list_dir_content(c);
			}
			goto here;

		case (KEY_RIGHT): // move cursor
			move_cursor_right(c);

			goto here;

		case (KEY_LEFT): // move cursor
			move_cursor_left(c);

			goto here;

		case (KEY_UP): // move cursor
			move_cursor_up(c);

			goto here;

		case (KEY_DOWN): // move cursor
			move_cursor_down(c);

			goto here;
		default:
			goto here;
	}
	cleanup(c); // endwin
}