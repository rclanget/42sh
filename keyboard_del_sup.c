/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_del_sup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 03:36:03 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/05 16:47:13 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

void    move_delete(t_info *info)
{
    int         plen;
    int         pos_c;
    t_termcaps  *term;

    term = info->term;
    pos_c = term->pos_c;
    plen = ft_strlen(term->prompt);
    if (pos_c)
    {
        ft_memcpy(&term->cmd[pos_c - 1], &term->cmd[pos_c],
            1 + ft_strlen(&term->cmd[pos_c]));
        move_cursor(term->capa, term->pos_c , plen, term->pos_c - 1);
        termcaps_print(info, term->cmd, 0);
        move_cursor(term->capa, term->pos_c , plen, term->pos_c - 1);
        --term->pos_c;
    }
    else
        ft_putstr(term->capa->str_bl);
}

void    move_supp(t_info *info)
{
    int         plen;
    int         pos_c;
    t_termcaps  *term;

    term = info->term;
    pos_c = term->pos_c;
    plen = ft_strlen(term->prompt);
    if (term->cmd[pos_c])
    {
        ft_memcpy(&term->cmd[pos_c], &term->cmd[pos_c + 1],
            1 + ft_strlen(&term->cmd[pos_c]));
        ++term->pos_c;
        termcaps_print(info, term->cmd, 0);
        move_cursor(term->capa, term->pos_c , plen, term->pos_c - 1);
        --term->pos_c;
    }
    else
        ft_putstr(term->capa->str_bl);
}
