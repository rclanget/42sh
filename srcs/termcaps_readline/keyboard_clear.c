/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:59:07 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 14:16:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"

void    move_clear_left(t_info *info)
{
    int         len;
    int         plen;
    int         pos_c;
    t_termcaps  *term;

    term = info->term;
    pos_c = term->pos_c;
    len = ft_strlen(&term->cmd[pos_c]);
    plen = ft_strlen(term->prompt);
    if (pos_c)
    {
        ft_memcpy(term->cmd, &term->cmd[pos_c], 1 +len);
        ft_bzero(&term->cmd[len], BUFFER_SIZE - len);
        move_cursor(term->capa, term->pos_c , plen, 0);
        ft_putstr(term->capa->str_cd);
        ft_putstr(term->cmd);
        if (plen + len)
          write(1, "\n", ((plen + len) % termcap_winsz_x()) ? 0 : 1);
        move_cursor(term->capa, len , plen, 0);
        term->pos_c = 0;
    }
    else
        ft_putstr(term->capa->str_bl);
}

void    move_clear_right(t_info *info)
{
	int			len;
	int			pos_c;
	t_termcaps 	*term;

	term = info->term;
	pos_c = term->pos_c;
	len = ft_strlen(term->cmd) - ft_strlen(&term->cmd[pos_c]);
	if (pos_c)
	{
		ft_bzero(&term->cmd[pos_c], BUFFER_SIZE - len);
		ft_putstr(term->capa->str_cd);
	}
	else
		ft_putstr(term->capa->str_bl);
}

void    move_clear_screen(t_info *info)
{
	int			len;
	int			plen;
	t_termcaps	*term;

	term = info->term;
	ft_putstr(term->capa->str_ho);
	ft_putstr(term->capa->str_cd);
	ft_putstr(term->prompt);
	ft_putstr(term->cmd);
	len = ft_strlen(term->cmd);
	plen = ft_strlen(term->prompt);
	if (plen + len)
	  write(1, "\n", ((plen + len) % termcap_winsz_x()) ? 0 : 1);
	move_cursor(term->capa, len, plen, term->pos_c);
}
