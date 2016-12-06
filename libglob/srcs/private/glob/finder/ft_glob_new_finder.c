/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:17:41 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_finder.h"
#include "glob_string.h"
#include <stdlib.h>

void		ft_glob_new_finder(char const *match)
{
	t_glob_finder *new;

	if (0 != (new = (t_glob_finder *)malloc(sizeof(t_glob_finder))))
	{
		if ('.' == *match && '/' == *(match + 1))
			match += 2;
		new->handle = ft_string_dup(match);
		ft_list_add_tail(&new->list, &ft_singleton_glob()->finder_head);
	}
}
