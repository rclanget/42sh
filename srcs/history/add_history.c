/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 13:58:45 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/28 14:41:51 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "history.h"

void				add_history(t_info *info, char *cmd)
{
	t_history		*node;
	static int 		number;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_history))))
	{
		node->cmd = ft_strdup(cmd);
		node->n = number++;
		if ((node->next = info->hist))
			node->next->prev = node;
		info->hist = node;
	}
}
