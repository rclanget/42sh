/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_updown.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:19:54 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 15:57:44 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "history.h"
#include "command_line_termcaps.h"

#include <unistd.h>

void	move_up(t_info *info)
{
	t_termcaps	*term;

	term = info->term;
	if (info->hist && info->hist->next)
	{
		move_cursor(term->capa, term->pos_c, ft_strlen(term->prompt), 0);
		ft_putstr(term->capa->str_cd);
		info->hist = info->hist->next;
		term->cmd = info->hist->cmd;
		term->pos_c = write(1, term->cmd, ft_strlen(term->cmd));
	}
}

void	move_down(t_info *info)
{
	t_termcaps	*term;

	term = info->term;
	if (info->hist && info->hist->prev)
	{
		move_cursor(term->capa, term->pos_c, ft_strlen(term->prompt), 0);
		ft_putstr(term->capa->str_cd);
		info->hist = info->hist->prev;
		term->cmd = info->hist->cmd;
		term->pos_c = write(1, term->cmd, ft_strlen(term->cmd));
	}
}
