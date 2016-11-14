/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:06:09 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 12:33:00 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

void				update_path(t_info *info, t_env *path)
{
	static char		*previous = NULL;

	if (path && path->content)
	{
		if (!previous || ft_strcmp(previous, path->content))
		{
			hashmap_free(info->hash);
			info->hash = pre_creer_hashmap(ft_strdup(path->content), NULL);
		}
	}
	else if (previous)
	{
		hashmap_free(info->hash);
		info->hash = pre_creer_hashmap(NULL, NULL);
	}
	if (previous)
		free(previous);
	previous = (path && path->content) ? ft_strdup(path->content) : NULL;
}
