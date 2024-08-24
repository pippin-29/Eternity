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

iP_1 compare_entries(const none *a, const none *b) {
	const t_file_entries *entryA = a;
	const t_file_entries *entryB = b;
    return strcmp(entryA->name, entryB->name);
}

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

	i = 2;
	while ((c->entry = readdir(c->directory)))
	{
		if (strcmp(c->entry->d_name, "..") == 0)
		{
			c->file_entries[1].name = dc_strdup(c->entry->d_name);
			c->file_entries[1].type = c->entry->d_type;
			continue ;
		}
		if (strcmp(c->entry->d_name, ".") == 0)
		{
			c->file_entries[0].name = dc_strdup(c->entry->d_name);
			c->file_entries[0].type = c->entry->d_type;
			continue ;
		}
		c->file_entries[i].name = dc_strdup(c->entry->d_name);
		c->file_entries[i].type = c->entry->d_type;
		i++;
	}
	qsort(c->file_entries + 2, i - 2, sizeof(t_file_entries), compare_entries);
	closedir(c->directory);
}