/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_historic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 15:30:16 by ulefebvr          #+#    #+#             */
/*   Updated: 2015/11/01 17:52:47 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#include <stdio.h>

void		add_historic(t_info *info, t_term *line)
{
	t_histc		*elem;
	int			i;

	i = 0;
	if ((elem = (t_histc *)malloc(sizeof(t_histc))))
	{
		elem->line = lst_cpy(line);
		elem->prev = NULL;
		elem->next = info->historic;
		elem->number = (info->historic) ? info->historic->number + 1 : 0;
		if (info->historic)
    		info->historic->prev = elem;
		info->historic = elem;
	}
	if ((elem = info->historic))
	{
		while (elem)
		{
			elem = elem->next;
			i++;
		}
		if (i > MAX_HISTORIC)
			remove_historic(info);
	}
}
