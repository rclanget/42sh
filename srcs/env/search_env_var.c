/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 13:12:32 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 12:30:49 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

t_env		*search_env_var(t_info *info, char *var)
{
	t_env	*cpy;

	cpy = info->env;
	while (cpy)
	{
		if (!ft_strcmp(cpy->var, var))
			break ;
		cpy = cpy->next;
	}
	return (cpy);
}
