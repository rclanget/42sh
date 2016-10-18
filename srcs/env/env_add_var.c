/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 13:44:06 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 12:26:48 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#include <stdlib.h>

void		env_add_var(t_info *info, char *var, char *content)
{
	t_env	*elem;
	t_env	*last;

	elem = (t_env *)malloc(sizeof(t_env));
	elem->var = var;
	elem->content = content;
	elem->next = NULL;
	if ((last = info->env))
	{
		while (last && last->next)
			last = last->next;
		last->next = elem;
	}
	else
		info->env = elem;
}
