/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 18:48:28 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 12:27:10 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

#include <stdlib.h>

void	env_update_var(t_info *info, char *var, char *content)
{
	t_env	*tmp;

	if ((tmp = search_env_var(info, var)))
	{
		free(tmp->content);
		tmp->content = ft_strdup(content);
	}
	else
		env_add_var(info, ft_strdup(var), ft_strdup(content));
}
