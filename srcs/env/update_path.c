/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:06:09 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 19:31:00 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

void				update_path(t_info *info, t_env *path)
{
	char			*tmp;
	static char		*previous = NULL;

	tmp = ft_strdup((path && path->content) ? path->content : " ");
	if (!previous && (!path || !path->content))
		return ;
	else if (!previous || (tmp && ft_strcmp(tmp, previous)))
	{
		hashmap_free(info->hash);
		info->hash = pre_creer_hashmap(ft_strdup(tmp), NULL);
	}
	ft_free_them_all(1, &tmp);
	previous = (path && path->content) ? path->content : NULL;
}
