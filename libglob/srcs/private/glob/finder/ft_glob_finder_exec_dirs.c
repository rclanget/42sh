/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_exec_dirs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 18:03:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_finder.h"
#include "glob_match.h"
#include "glob_token.h"
#include "glob_libft.h"

bool		ft_glob_finder_exec_dirs(char const *joined,
				char const *pattern, char const *name)
{
	char			*here;
	char			*next;
	bool			res;

	res = false;
	here = GLOB_HERE(pattern);
	next = GLOB_NEXT(pattern);
	if (true == ft_glob_finder_try_match(name, here))
	{
		if (0 == next || GLOB_EOS == *next)
		{
			res = true;
			ft_glob_new_finder(joined);
		}
		if (true == ft_glob_finder_is_dir(joined))
		{
			if (ft_tiny_strcmp(name, ".") && ft_tiny_strcmp(name, ".."))
				if (true == ft_glob_finder_exec(joined, next))
					res = true;
		}
	}
	free(here);
	return (res);
}
