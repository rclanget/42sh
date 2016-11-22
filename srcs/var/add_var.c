/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:29:06 by zipo              #+#    #+#             */
/*   Updated: 2016/11/22 23:36:43 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias_struct.h"
#include "shell.h"

void	add_var(t_info *info, char *var, char *content)
{
	t_alias	*elem;
	t_alias	*tmp;

	elem = (t_alias *)ft_memalloc(sizeof(t_alias));
	elem->init = var;
	elem->replace = content;
	if ((tmp = info->var))
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		info->var = elem;
}
