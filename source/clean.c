//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/clean.c                                                     ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//


# include "../includes/eternity.h"

t_cleanup_function	cleanup(t_program *c)
{
	if (c->title)
		free(c->title);
	free_file_entries(c->file_entries, c->filecount);
	if (c->copyfile)
		free(c->copyfile);
	if (c->copyfilename)
		free(c->copyfilename);

	endwin();
	if (c)
		free(c);
}

none	free_file_entries(t_file_entries *f, iP_1 fc)
{
	iP_1 i;

	i = 0;
	while (i < fc)
	{
		if (f[i].name)
			free(f[i].name);
		i++;
	}
	free(f);
}
