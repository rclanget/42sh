/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_move_cursor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:34:42 by zipo              #+#    #+#             */
/*   Updated: 2016/01/30 18:52:55 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

void move_cursor_left(t_info *info)
{
    t_termcaps *term;

    term = info->term;
    if ((term->pos_c > 0) && term->cmd[term->pos_c - 1])
    {
        ft_putstr(term->capa->str_le);
        term->pos_c--;
    }
}

void move_cursor_right(t_info *info)
{
    t_termcaps *term;

    term = info->term;
    if (term->cmd[term->pos_c])
    {
        ft_putstr(term->capa->str_ri);
        term->pos_c++;
    }
}
