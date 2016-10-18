/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_alias.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 18:34:05 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:17:35 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "alias_struct.h"
#include <stdlib.h>

void	add_alias(t_info *info, char *var, char *content)
{
	t_alias	*elem;
	t_alias	*tmp;

	elem = (t_alias *)malloc(sizeof(t_alias));
	elem->init = var;
	elem->replace = content;
	elem->next = NULL;
	if ((tmp = info->alias))
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		info->alias = elem;
}
