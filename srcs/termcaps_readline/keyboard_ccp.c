/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_ccp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:28:54 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/26 15:12:41 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "keyboard_keys.h"
#include "libft.h"

#define MIN(a,b) (a < b ? a : b)
#define MAX(a,b) (a > b ? a : b)

void		cut_line(t_info *info)
{
	char	*selection;
	int		start;
	int		plen;
	int		slen;

	start = info->term->pos_c;
	if ((selection = get_selection(info)))
	{
		plen = ft_strlen(info->term->prompt);
		slen = ft_strlen(selection);
		if (info->term->save_cmd)
			free(info->term->save_cmd);
		info->term->save_cmd = selection;
		ft_memcpy(&info->term->cmd[MIN(start, info->term->pos_c)],
			&info->term->cmd[MAX(start, info->term->pos_c)],
			ft_strlen(&info->term->cmd[MAX(start, info->term->pos_c)]));
		ft_bzero(&info->term->cmd[ft_strlen(info->term->cmd) - slen],
			sizeof(char) * slen);
		move_cursor(info->term->capa, info->term->pos_c, plen, 0);
		ft_print("%s%s", info->term->capa->str_cd, info->term->cmd);
		move_cursor(info->term->capa, ft_strlen(info->term->cmd), plen,
			(info->term->pos_c = MIN(start, info->term->pos_c)));
	}
}

void		copy_line(t_info *info)
{
	char	*selection;

	if ((selection = get_selection(info)))
	{
		if (info->term->save_cmd)
			free(info->term->save_cmd);
		info->term->save_cmd = ft_strdup(selection);
		free(selection);
	}
}

void		paste_line(t_info *info)
{
	int			plen;
	int			slen;
	int			p;
	t_termcaps	*term;
	char		*buf;

	term = info->term;
	p = term->pos_c;
	if (term->save_cmd)
	{
		plen = ft_strlen(term->prompt);
		slen = ft_strlen(term->save_cmd);
		if ((ft_strlen(term->cmd) + slen) < BUFFER_SIZE)
		{
			buf = ft_strdup(term->cmd);
			ft_memcpy(&term->cmd[p + slen], buf + p, ft_strlen(term->cmd) - p);
			free(buf);
			ft_memcpy(&term->cmd[p], term->save_cmd, slen);
			move_cursor(term->capa, p, plen, 0);
			ft_putstr(term->cmd);
			move_cursor(term->capa, ft_strlen(term->cmd), plen, p + slen);
			term->pos_c = p + slen;
		}
	}
}
