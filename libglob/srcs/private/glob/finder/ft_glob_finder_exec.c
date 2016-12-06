/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 18:03:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_match.h"
#include "glob_token.h"
#include "glob_libft.h"
#include <sys/stat.h>
#include <dirent.h>

bool		ft_glob_finder_exec(char const *path, char const *pattern)
{
	DIR				*rep;
	struct dirent	*d;
	bool			res;
	char			*joined;

	res = 0;
	if (0 != pattern && GLOB_EOS != *pattern && 0 != (rep = opendir(path)))
	{
		while (0 != (d = readdir(rep)))
		{
			if (!ft_tiny_strcmp(d->d_name, ".")
				|| !ft_tiny_strcmp(d->d_name, ".."))
				if ('.' != *pattern || 0 == GLOB_NEXT(pattern))
					continue ;
			joined = ft_glob_finder_join_dirs(path, d->d_name);
			if (true == ft_glob_finder_exec_dirs(joined, pattern, d->d_name))
				res = true;
			free(joined);
		}
		closedir(rep);
	}
	return (res);
}
