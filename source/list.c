//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/source/list.c                                                      ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#include "../includes/eternity.h"



none	list_dir_content(t_program *c)
{
	free_file_entries(c->file_entries, c->filecount);
	c->directory = opendir(c->cwd);
	if (!c->directory)
		dc_ERROR_MEM(c, "opendir(c->cwd)");

	c->filecount = 0;
	while ((c->entry = readdir(c->directory)))
		c->filecount += 1;

	c->file_entries = malloc(sizeof(t_file_entries) * c->filecount);
	rewinddir(c->directory);

	iP_1	i;

	i = 0;
	while ((c->entry = readdir(c->directory)))
	{
		c->file_entries[i].name = dc_strdup(c->entry->d_name);
		c->file_entries[i].type = c->entry->d_type;
		i++;
	}
	closedir(c->directory);
}