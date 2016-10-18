/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 10:03:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:04:06 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

char    *executable_search(t_info *info, char *exec)
{
	t_hashmap    *tmp;

	tmp = info->hash;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, exec))
		break;
		tmp = tmp->next;
	}
	return (tmp ? ft_strdup(tmp->value) : NULL);
}
