/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:26 by rclanget         ###   ########.fr       */
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
