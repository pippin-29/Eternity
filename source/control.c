//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/control.c                                                   ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Mon Aug 19 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//


#include "../includes/eternity.h"

none run_(t_program *c)
{

here:
	erase();
	draw_(c);
	move(c->cursorY, c->cursorX);
	refresh();

	switch (c->in = getch())
	{
		case (CTRL_y): // yosh.i shell
			endwin();
			system("bash");
			initscr();
			keypad(stdscr, TRUE);
			list_dir_content(c);
			goto here;

		case(CTRL_q): // quit
			clear();
			break ;
		
		case(ESC):
			c->isamover = 0;
			c->copyfile = NULL;
			c->copyfilename = NULL;
			goto here;

		case(CTRL_b): // paste file/folder
			if (c->copyfile && c->copyfilename)
			{
				if (c->isamover == 0)
				{
					c->usefile = dc_strjoin_e(8, "cp -r", " ", c->copyfile, " ", c->cwd, "/", c->copyfilename, ">/dev/null 2>&1");
					system(c->usefile);
					free(c->usefile);
					list_dir_content(c);					
				}
				else if (c->isamover == 1)
				{
					c->usefile = dc_strjoin_e(7, "mv", " ", c->copyfile, " ", c->cwd, "/", c->copyfilename, ">/dev/null 2>&1");
					system(c->usefile);
					free(c->usefile);
					list_dir_content(c);	
				}

			}
			goto here;

		case(CTRL_u): // copy file/folder
			if (c->fileselected == 1)
			{
				if (c->file_entries[c->currentfile].type == REG_FILE)
				{
					if (c->copyfile)
						free(c->copyfile);
					if (c->copyfilename)
						free(c->copyfilename);
					c->isamover = 0;
					c->fileselected = 0;
					c->copyfilename = dc_strdup(c->file_entries[c->currentfile].name);
					c->copyfile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
					list_dir_content(c);
				}
				else if (c->file_entries[c->currentfile].type == DIRECTORY)
				{
					if (c->copyfile)
						free(c->copyfile);
					if (c->copyfilename)
						free(c->copyfilename);
					c->isamover = 0;
					c->fileselected = 0;
					c->copyfilename = dc_strdup(c->file_entries[c->currentfile].name);
					c->copyfile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
					list_dir_content(c);
				}			
			}
			goto here;

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
			if (c->fileselected == 1)
			{
				if (c->file_entries[c->currentfile].type == REG_FILE)
				{
					c->fileselected = 0;
					c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
					remove(c->usefile); 
					free(c->usefile);

					list_dir_content(c);
				}
				else if (c->file_entries[c->currentfile].type == DIRECTORY)
				{
					c->fileselected = 0;
					c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
					rmdir(c->usefile); 
					free(c->usefile);
					list_dir_content(c);
				}			
			}
			goto here;

		case(CTRL_i): // inserts file
			endwin();
			system("nano");
			initscr();
			keypad(stdscr, TRUE);
			list_dir_content(c);
			goto here;

		case(CTRL_o): // inserts folder
			i_H buffer[128];
			mvprintw(42, 1, "Folder Name:");
			cbreak();
			echo();
			mvscanw(42, 15, "%127s", buffer);
			c->usefile = dc_strdup(buffer);
			noecho();
			refresh();
			mkdir(c->usefile, 0755);
			free(c->usefile);
			list_dir_content(c);
			goto here;

		case(CTRL_t): // renames file/folder
			if (c->fileselected == 1)
			{
				c->fileselected = 0;
				i_H buffer[128];
				mvprintw(42, 1, "File/Folder Name:");
				cbreak();
				echo();
				mvscanw(42, 20, "%127s", buffer);
				c->usefile = dc_strjoin_e(5, "mv", " ", c->file_entries[c->currentfile].name, " ",  buffer);
				system(c->usefile);
				noecho();
				refresh();
				free(c->usefile);
				list_dir_content(c);
			}
			goto here;

			case(CTRL_a): // moves file/folder
			if (c->fileselected == 1)
			{
				if (c->file_entries[c->currentfile].type == REG_FILE)
				{
					c->isamover = 1;
					if (c->copyfile)
						free(c->copyfile);
					if (c->copyfilename)
						free(c->copyfilename);
					c->fileselected = 0;
					c->copyfilename = dc_strdup(c->file_entries[c->currentfile].name);
					c->copyfile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
					list_dir_content(c);
				}
				else if (c->file_entries[c->currentfile].type == DIRECTORY)
				{
					c->isamover = 1;
					if (c->copyfile)
						free(c->copyfile);
					if (c->copyfilename)
						free(c->copyfilename);
					c->fileselected = 0;
					c->copyfilename = dc_strdup(c->file_entries[c->currentfile].name);
					c->copyfile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
					list_dir_content(c);
				}
			}
			goto here;

		case('\n'): // Use File or Folder
			if (c->fileselected == 1)
			{
				if (c->file_entries[c->currentfile].type == REG_FILE)
				{
					c->fileselected = 0;
					endwin();
					c->usefile = dc_strjoin_e(5, "nano", " ", c->cwd, "/", c->file_entries[c->currentfile].name);
					system(c->usefile); free(c->usefile);
					initscr();
					keypad(stdscr, TRUE);
					list_dir_content(c);				
				} 
				else if (c->file_entries[c->currentfile].type == DIRECTORY)
				{
					c->fileselected = 0;
					c->usefile = dc_strjoin_e(3, c->cwd, "/", c->file_entries[c->currentfile].name);
					chdir(c->usefile);
					free(c->usefile);
					getcwd(c->cwd, 1024);
					list_dir_content(c);
				}				
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