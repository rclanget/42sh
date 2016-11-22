/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:30:02 by zipo              #+#    #+#             */
/*   Updated: 2016/11/22 23:36:40 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias_struct.h"
#include "shell.h"

void		remove_var(t_info *info, char *var)
{
	t_alias	*cpy;
	t_alias	*prev;
	t_alias	*tmp;

	prev = NULL;
	cpy = info->var;
	while (cpy && var)
	{
		if (!ft_strcmp(cpy->init, var))
		{
			tmp = cpy;
			cpy = cpy->next;
			if (prev)
				prev->next = cpy;
			else
				info->var = cpy;
			ft_free_them_all(3, &tmp->init, &tmp->replace, &tmp);
			break ;
		}
		prev = cpy;
		cpy = cpy->next;
	}
}
