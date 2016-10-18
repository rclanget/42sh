/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 15:00:52 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:21:03 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "alias_struct.h"

void		remove_alias(t_info *info, char *var)
{
	t_alias	*cpy;
	t_alias	*prev;
	t_alias	*tmp;

	prev = NULL;
	cpy = info->alias;
	while (cpy && var)
	{
		if (!ft_strcmp(cpy->init, var))
		{
			tmp = cpy;
			cpy = cpy->next;
			if (prev)
				prev->next = cpy;
			else
				info->alias = cpy;
			free(tmp->init);
			free(tmp->replace);
			free(tmp);
			break ;
		}
		prev = cpy;
		cpy = cpy->next;
	}
}
