/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:31:18 by zipo              #+#    #+#             */
/*   Updated: 2016/11/22 23:36:31 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias_struct.h"
#include "alias.h"
#include "libft.h"
#include "var.h"
#include "shell.h"

void	update_var(t_info *info, char *init, char *replace)
{
	t_alias	*var;

	if ((var = search_alias(info, init)) || (var = search_var(info, init)))
	{
		free(var->replace);
		var->replace = ft_strdup(replace);
	}
	else
		add_var(info, ft_strdup(init), ft_strdup(replace));
}
