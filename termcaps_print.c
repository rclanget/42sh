/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 23:36:35 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/28 23:23:17 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "command_line_termcaps.h"

#include <unistd.h>
#include <termcap.h>

void    move_cursor(int x, int y)
{
    char    *cm;
    char    *move;

    if ((cm = tgetstr("cm", NULL)))
    {
        if ((move = tgoto(cm, x, y)))
        {
            ft_putstr(move);
        }
    }
    return ;
}

void    clear_cmd(t_termcaps *term)
{
    move_cursor(term->init_x, term->init_y);
    ft_putstr(term->capa->str_cd);
}

int     termcaps_print(t_info *info, char *cmd)
{
    clear_cmd(info->term);
    ft_putstr(info->term->cmd);
    return (1);
}
