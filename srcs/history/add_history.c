/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:58:45 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/12 15:10:39 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "history.h"

char				*replace_nl(char *str)
{
	int				i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		++i;
	}
	return (str);
}

char				*add_history(t_info *info, char *cmd)
{
	t_history		*node;
	static int 		number;

	node = NULL;
	if (ft_strlen(cmd) && (node = ft_memalloc(sizeof(t_history))))
	{
		node->cmd = replace_nl(ft_strdup(cmd));
		node->n = number++;
		if ((node->next = info->hist))
			node->next->prev = node;
		info->hist = node;
	}
	return (cmd);
}
