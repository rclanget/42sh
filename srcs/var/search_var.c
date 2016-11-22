/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:30:48 by zipo              #+#    #+#             */
/*   Updated: 2016/11/22 23:36:37 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias_struct.h"
#include "shell.h"

t_alias		*search_var(t_info *info, char *var)
{
	t_alias		*v;

	v = info->var;
	while (v && var)
	{
		if (!ft_strcmp(v->init, var))
			break ;
		v = v->next;
	}
	return (v);
}
