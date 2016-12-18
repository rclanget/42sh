/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_fn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:16:46 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/18 19:04:43 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>

char **treat_tab(char **tab_fullpath)
{
	int i = 0;
	int dot = 0;

	while (tab_fullpath && tab_fullpath[i])
	{
		if (!ft_strcmp(tab_fullpath[i], ".")
			|| (++dot && !ft_strcmp(tab_fullpath[i], "..")))
		{
			if (!i)
				dot = 0;
			while (tab_fullpath[i + dot])
			{
				tab_fullpath[i - dot] = tab_fullpath[i + 1];
				i++;
			}
			tab_fullpath[i - dot] = 0;
			i = 0 - dot;
		}
		dot = 0;
		++i;
	}
	return (tab_fullpath);
}

char *create_fullpath(char *pwd, char *dest, int flagl)
{
	char **tab_pwd;
	char **tab_dest;
	char **tab_fullpath;
	char *fullpath;
	int i;

	i = -1;
	fullpath = 0;
	pwd = pwd ? pwd : getcwd(NULL, 1048);
	fullpath = (char *)ft_memalloc(sizeof(char) * strlen(pwd) + strlen(dest));
	tab_pwd = ft_strsplit(pwd, '/');
	tab_dest = ft_strsplit(dest, '/');
	tab_fullpath = ft_tabjoin(tab_pwd, tab_dest);
	tab_fullpath = treat_tab(tab_fullpath);
	if (!tab_fullpath[0])
		strcat(fullpath, "/");
	while (tab_fullpath[++i])
		strcat(strcat(fullpath, "/"), tab_fullpath[i]);
	free_tab(tab_dest);
	free_tab(tab_pwd);
	free(tab_fullpath);
	return (fullpath);
}

char *getfullpath(char *pwd, char *dest, int flagl)
{
	char *fullpath;
	struct stat status;

	if (dest && dest[0] == '/')
		fullpath = ft_strdup(dest);
	else
		fullpath = create_fullpath(pwd, dest, flagl);
	if (-1 == stat(fullpath, &status))
		ft_memdel((void **)&fullpath);
	return (fullpath);
}
