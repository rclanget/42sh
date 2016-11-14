/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_ccp_fn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:58:33 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 15:59:56 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "keyboard_keys.h"
#include "libft.h"

#define MIN(a,b) (a < b ? a : b)
#define MAX(a,b) (a > b ? a : b)

static t_key g_key_tab[] =
{
	{MYKEY_RIGHT, move_cursor_right},
	{MYKEY_LEFT, move_cursor_left},
	{CTRL_A, move_start},
	{KEY_START, move_start},
	{CTRL_E, move_end},
	{KEY_END, move_end},
	{CTRL_UP, move_line_up},
	{CTRL_DOWN, move_line_down},
	{CTRL_RIGHT, move_word_right},
	{CTRL_LEFT, move_word_left}
};

void		underline(t_info *info, int start, int end)
{
	int		len;
	int		plen;

	len = ft_strlen(info->term->cmd);
	plen = ft_strlen(info->term->prompt);
	move_cursor(info->term->capa, info->term->pos_c, plen, 0);
	write(1, info->term->cmd, start);
	ft_print("%s", info->term->capa->str_us);
	write(1, &info->term->cmd[start], end - start);
	ft_print("%s", info->term->capa->str_ue);
	write(1, &info->term->cmd[end], len - end);
	move_cursor(info->term->capa, len, plen, info->term->pos_c);
}

int			termcaps_goto(t_info *info, long chr, int rs)
{
	int		i;
	int		end;

	i = 0;
	while (i < 10)
	{
		if (g_key_tab[i].key == chr)
		{
			g_key_tab[i].f(info);
			end = info->term->pos_c;
			underline(info, MIN(rs, end), MAX(rs, end));
			return (1);
		}
		++i;
	}
	return (0);
}

char		*get_selection(t_info *info)
{
	int		ret;
	long	chr;
	int		s;
	int		e;

	e = 0;
	chr = 0;
	s = info->term->pos_c;
	while ((ret = read(0, &chr, sizeof(chr))) > 0)
	{
		if ((chr == NL) || (chr == CTRL_D && (ret = -1) == -1))
		{
			e = info->term->pos_c;
			break ;
		}
		if (!termcaps_goto(info, chr, s))
			return (NULL);
		chr = 0;
	}
	return (ft_strsub(info->term->cmd, MIN(s, e), MAX(s, e) - MIN(s, e)));
}
