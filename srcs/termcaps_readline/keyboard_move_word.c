/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_move_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:40:13 by zipo              #+#    #+#             */
/*   Updated: 2016/11/14 15:50:15 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "command_line_termcaps.h"
#include "keyboard_keys.h"

static int		ft_isspace(int c)
{
	if (c == '\f')
		return (1);
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v');
}

void			move_word_left(t_info *info)
{
	t_termcaps			*term;
	int					pos;
	int					word;

	term = info->term;
	pos = term->pos_c;
	word = 0;
	while (--pos > 0)
	{
		if (!word && term->cmd[pos] != ' ')
			word = 1;
		else if (word && term->cmd[pos] == ' ')
			break ;
	}
	move_cursor(term->capa, term->pos_c,
		ft_strlen(term->prompt), (pos ? ++pos : 0));
	term->pos_c = pos;
}

void			move_word_right(t_info *info)
{
	t_termcaps			*term;
	int					pos;
	int					len;

	term = info->term;
	pos = term->pos_c;
	len = ft_strlen(term->cmd);
	while ((pos < (len - 1)) && !ft_isspace(term->cmd[pos]))
		++pos;
	while (pos < len)
	{
		++pos;
		if (!ft_isspace(term->cmd[pos]))
			break ;
	}
	move_cursor(info->term->capa, info->term->pos_c,
		ft_strlen(term->prompt), pos);
	term->pos_c = pos;
}
