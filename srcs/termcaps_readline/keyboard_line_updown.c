/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_line_updown.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:40:50 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 15:47:00 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

#include "libft.h"

void	move_line_up(t_info *info)
{
	int			plen;
	int			pos_c;
	t_termcaps	*term;

	term = info->term;
	pos_c = term->pos_c;
	plen = ft_strlen(term->prompt);
	move_cursor(term->capa, pos_c, plen,
		(pos_c >= termcap_winsz_x()) ? pos_c - termcap_winsz_x() : 0);
	term->pos_c = (pos_c >= termcap_winsz_x()) ? pos_c - termcap_winsz_x() : 0;
}

void	move_line_down(t_info *info)
{
	int				len;
	int				plen;
	int				pos_c;
	t_termcaps		*term;

	term = info->term;
	pos_c = term->pos_c;
	len = ft_strlen(term->cmd);
	plen = ft_strlen(term->prompt);
	move_cursor(term->capa, pos_c, plen,
		((pos_c + termcap_winsz_x()) < len) ? pos_c + termcap_winsz_x() : len);
	term->pos_c =
		((pos_c + termcap_winsz_x()) < len) ? pos_c + termcap_winsz_x() : len;
}
