/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 15:05:05 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:19:51 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "alias_struct.h"
#include "libft.h"

t_alias		*search_alias(t_info *info, char *var)
{
	t_alias		*alias;

	alias = info->alias;
	while (alias && var)
	{
		if (!ft_strcmp(alias->init, var))
			break ;
		alias = alias->next;
	}
	return (alias);
}
