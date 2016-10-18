/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_remove_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:33:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 12:27:06 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

#include <stdlib.h>

void		env_remove_var(t_info *info, char *var)
{
	t_env	*cpy;
	t_env	*prev;
	t_env	*tmp;

	prev = NULL;
	cpy = info->env;
	while (cpy && var)
	{
		if (!ft_strcmp(cpy->var, var))
		{
			tmp = cpy;
			cpy = cpy->next;
			if (prev)
				prev->next = cpy;
			else
				info->env = cpy;
			free(tmp->var);
			free(tmp->content);
			free(tmp);
			return ;
		}
		prev = cpy;
		cpy = cpy->next;
	}
}
