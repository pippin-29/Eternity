//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/cursor.c                                                    ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Sun Aug 18 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

# include "../includes/eternity.h"

none	move_cursor_up(t_program *c)
{
	if (c->cursorY > 2)
		c->cursorY--;
}
none	move_cursor_down(t_program *c)
{
	if (c->cursorY < 31)
		c->cursorY++;
}
none	move_cursor_left(t_program *c)
{
	if (c->cursorX > 2)
		c->cursorX -= 32;
}
none	move_cursor_right(t_program *c)
{
	if (c->cursorX < 65)
		c->cursorX += 32;
}