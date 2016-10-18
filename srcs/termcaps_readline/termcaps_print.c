/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 23:36:35 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/07 18:35:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "command_line_termcaps.h"

#include <unistd.h>
#include <termcap.h>

void    move_cursor(t_capa *capa, int from, int plen, int to)
{
    int     x;
    int     y;
    int     rst_x;
    int     cpy_y;

    y = (((plen + from) / termcap_winsz_x())) -
        (((plen + to) / termcap_winsz_x()));
    x = (((plen + from) % termcap_winsz_x())) -
        (((plen + to) % termcap_winsz_x()));
    rst_x = (plen + from) % termcap_winsz_x();
    cpy_y = y;
    while (y)
    {
        ft_putstr((y > 0) ? capa->str_up : capa->str_do);
        y = (y > 0) ? y - 1 : y + 1;
    }
    while (cpy_y < 0 && rst_x--)
        ft_putstr(capa->str_ri);
    while (x)
    {
        ft_putstr((x > 0) ? capa->str_le : capa->str_ri);
        x = (x > 0) ? x - 1 : x + 1;
    }
}

int     termcaps_print(t_info *info, char *cmd, long chr)
{
    int len;
    int plen;

    if (chr && info->term->capa->flg_os
        && ((char)chr != '\n' || !info->term->capa->flg_eo))
    {
        write(1, (char *)&chr, 1);
    }
    else
    {
        len = ft_strlen(cmd);
        plen = ft_strlen(info->term->prompt);
        ft_putstr(info->term->capa->str_cd);
        ft_putstr(&info->term->cmd[info->term->pos_c - 1]);
        write(1, "\n", ((plen + len) % termcap_winsz_x()) ? 0 : 1);
        move_cursor(info->term->capa, len, plen, info->term->pos_c);
    }
    return (1);
}
