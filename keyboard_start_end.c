/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_start_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 03:02:42 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/05 15:27:02 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

void    move_start(t_info *info)
{
    int         plen;
    t_termcaps  *term;

    term = info->term;
    plen = ft_strlen(term->prompt);
    if (term->pos_c)
        move_cursor(term->capa, term->pos_c , plen, 0);
    else
        ft_putstr(term->capa->str_bl);
    term->pos_c = 0;
}

void    move_end(t_info *info)
{
    int         len;
    int         plen;
    t_termcaps  *term;

    term = info->term;
    len = ft_strlen(term->cmd);
    plen = ft_strlen(term->prompt);
    if (term->pos_c != len)
        move_cursor(term->capa, term->pos_c , plen, len);
    else
        ft_putstr(term->capa->str_bl);
    term->pos_c = len;
}
