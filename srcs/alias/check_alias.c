/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alias.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 15:16:10 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:18:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "alias.h"
#include "alias_struct.h"

char	*check_alias(t_info *info, char *init)
{
	t_alias		*alias;
	char		*ret;

	ret = NULL;
	if ((alias = search_alias(info, init)))
	{
		ret = (alias->replace && alias->replace[0] == '\'') ?
			ft_strndup(&alias->replace[1], ft_strlen(alias->replace) - 2) :
			ft_strdup(alias->replace);
	}
	return (ret);
}
