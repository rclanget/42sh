/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_fn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:16:46 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/26 15:23:28 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>

char	**treat_tab(char **tab_fullpath)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
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

char	*create_fullpath(char *pwd, char *dest)
{
	char	**tab_pwd;
	char	**tab_dest;
	char	**tab_fullpath;
	char	*fullpath;
	int		i;

	i = -1;
	fullpath = 0;
	pwd = pwd ? pwd : getcwd(NULL, 1048);
	fullpath = (char *)ft_memalloc(
		sizeof(char) * (strlen(pwd) + strlen(dest) + 2));
	tab_pwd = ft_strsplit(pwd, '/');
	tab_dest = ft_strsplit(dest, '/');
	tab_fullpath = ft_tabjoin(tab_pwd, tab_dest);
	tab_fullpath = treat_tab(tab_fullpath);
	if (!tab_fullpath[0])
		ft_strcat(fullpath, "/");
	while (tab_fullpath[++i])
		ft_strcat(ft_strcat(fullpath, "/"), tab_fullpath[i]);
	free_tab(tab_dest);
	free_tab(tab_pwd);
	free(tab_fullpath);
	return (fullpath);
}

char	*get_physical_path(char *fullpath)
{
	char	*tmp;
	char	*tmp2;

	if (0 != (tmp = getcwd(NULL, 1048)))
	{
		if (-1 != chdir(fullpath) && 0 != (tmp2 = getcwd(NULL, 1048)))
		{
			chdir(tmp);
			ft_memdel((void **)&fullpath);
			fullpath = tmp2;
		}
		ft_memdel((void **)&tmp);
	}
	return (fullpath);
}

char	*getfullpath(char *pwd, char *dest, int flagl)
{
	char			*fullpath;
	struct stat		status;

	if (dest && dest[0] == '/')
		fullpath = ft_strdup(dest);
	else
		fullpath = create_fullpath(pwd, dest);
	if (-1 == stat(fullpath, &status))
		ft_memdel((void **)&fullpath);
	if (fullpath && flagl)
		fullpath = get_physical_path(fullpath);
	return (fullpath);
}
