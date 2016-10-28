/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:48:06 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/28 14:24:16 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "history.h"
#include "command_line_termcaps.h"

t_history				*get_head(t_history *history)
{
	if (history && history->prev)
		return (get_head(history->prev));
	return (history);
}

t_history				*copy_history(t_history *hist)
{
	t_history			*cpy;

	cpy = NULL;
	if (hist && (cpy = ft_memalloc(sizeof(t_history))))
	{
		cpy->cmd = ft_memalloc(BUFFER_SIZE);
		ft_strcpy(cpy->cmd, hist->cmd);
		if ((cpy->next = copy_history(hist->next)))
			cpy->next->prev = cpy;
	}
	return (cpy);
}

t_history				*add_current(t_history *hist)
{
	t_history			*current;

	if ((current = ft_memalloc(sizeof(t_history))))
	{
		current->cmd = ft_memalloc(BUFFER_SIZE);
		if ((current->next = hist))
			current->next->prev = current;
	}
	return (current);
}

void					set_temporary_hist(t_info *info, int set)
{
	static t_history	*save;

	if (set)
	{
		save = info->hist;
		info->hist = add_current(copy_history(get_head(info->hist)));
		info->term->cmd = info->hist->cmd;
	}
	else
	{
		free_history(get_head(info->hist));
		info->hist = save;
		info->term->cmd = NULL;
	}
}
