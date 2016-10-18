/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 15:04:38 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:20:16 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "alias.h"
#include "alias_struct.h"
#include "libft.h"

#include <stdlib.h>

void	update_alias(t_info *info, char *init, char *replace)
{
	t_alias	*alias;

	if ((alias = search_alias(info, init)))
	{
		free(alias->replace);
		alias->replace = ft_strdup(replace);
	}
	else
		add_alias(info, ft_strdup(init), ft_strdup(replace));
}
