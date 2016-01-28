/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 22:51:52 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/28 21:24:14 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

#include <unistd.h>

char        *return_string(char *cmd)
{
    ft_putstr("\n");
    termcaps_save(0);
    return (cmd);
}

int         initial_postion_cursor(t_termcaps *term)
{
    term->x = 0;
    term->y = 0;
    return (0);
}

char        *termcaps_loop(t_info *info)
{
    int                 ret;
    long                chr;

    initial_postion_cursor(info->term);
    while ((ret = read(0, &chr, sizeof(chr))) > 0)
    {
        if ((chr == NL) || (chr == CTRL_D && (ret = -1) == -1))
            break;
        termcaps_handle_keyboard(info, chr);
    }
    return ((ret == -1) ? NULL : return_string(info->term->cmd));
}
