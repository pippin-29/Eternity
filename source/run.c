//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/run.c                                                       ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
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
	mvprintw(4, 5, "You have tried to quit, are you sure?");
	mvprintw(5, 5, "__'y'__ to quit");
	switch (c->confirm = getch())
	{
		case('y'):
			break ;
		default:
			clear();
			refresh();
			goto here;
	}
	cleanup(c); // endwin
}