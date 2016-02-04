/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_move_cursor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:34:42 by zipo              #+#    #+#             */
/*   Updated: 2016/02/04 23:28:29 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

void move_cursor_left(t_info *info)
{
    int         len;
    int         plen;
    t_termcaps  *term;

    len = 0;
    plen = 0;
    term = info->term;
    if (term->pos_c > 0)
    {
        len = ft_strlen(term->cmd);
        plen = ft_strlen(term->prompt);
        move_cursor(term->capa, term->pos_c , plen, term->pos_c - 1);
        --term->pos_c;
    }
}

void move_cursor_right(t_info *info)
{
    int         len;
    int         plen;
    t_termcaps  *term;

    len = 0;
    plen = 0;
    term = info->term;
    if (term->cmd[term->pos_c])
    {
        len = ft_strlen(term->cmd);
        plen = ft_strlen(term->prompt);
        move_cursor(term->capa, term->pos_c , plen, term->pos_c + 1);
        ++term->pos_c;
    }
}
