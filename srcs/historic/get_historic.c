/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_historic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 11:39:05 by rclanget          #+#    #+#             */
/*   Updated: 2015/11/01 17:53:00 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_histc	*add_lk_historik(t_histc *cpy, t_histc *lk)
{
	t_histc *new;
	t_histc *begin;

	begin = cpy;
	if (!(new = (t_histc *)malloc(sizeof(t_histc))))
		return (NULL);
	new->line = lst_cpy(lk->line);
	new->number = lk->number;
	new->next = NULL;
	new->prev = NULL;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
		if (begin->next)
			begin->next->prev = begin;
	}
	else
		return (new);
	return (cpy);
}

t_histc	*get_historic(t_info *info)
{
	t_histc *cpy;
	t_histc	*begin;

	cpy = NULL;
	begin = info->historic;
	while (begin)
	{
		if (!(cpy = add_lk_historik(cpy, begin)))
			return (NULL);
		begin = begin->next;
	}
	return (cpy);
}
