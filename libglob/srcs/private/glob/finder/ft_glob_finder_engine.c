/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_engine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 17:37:34 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_finder.h"
#include <sys/stat.h>
#include <dirent.h>

char	*ft_glob_finder_engine(char const *line, void (*f)(char const *))
{
	char	*resolved;
	bool	success;
	char	**tab;
	size_t	i;

	if (0 == line || 0 == line || 0 == (tab = ft_glob_finder_split(line)))
		return (0);
	i = 0;
	success = true;
	while (true == success && 0 != *(tab + i))
	{
		if (0 == i || true == ft_glob_finder_ignore(*(tab + i)))
			ft_glob_new_finder(*(tab + i));
		else if (false == ft_glob_finder_exec(GLOB_PATH(tab[i]), tab[i]))
			success = false;
		++i;
	}
	resolved = 0;
	if (true == success)
		resolved = ft_glob_finder_build();
	else
		f(*(tab + i - 1));
	ft_glob_finder_tab_del(&tab);
	ft_list_apply(&ft_singleton_glob()->finder_head, &ft_glob_finder_del);
	return (resolved);
}
