/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 23:36:35 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/31 19:36:15 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "command_line_termcaps.h"

#include <unistd.h>
#include <termcap.h>

void    move_cursor(t_capa *capa, int len, int plen, int pos_c)
{
    int     x;
    int     y;

    y = (((plen + len) / termcap_winsz_x()) + 1) -
        (((plen + pos_c) / termcap_winsz_x()) + 1);
    x = (((plen + len) % termcap_winsz_x()) + 1) -
        (((plen + pos_c) % termcap_winsz_x()) + 1);
    while (y)
    {
        ft_putstr(capa->str_up);
        --y;
    }
    while (x)
    {
        ft_putstr((x > 0) ? capa->str_le : capa->str_ri);
        x = (x > 0) ? x - 1 : x + 1;
    }
}

int     termcaps_print(t_info *info, char *cmd)
{
    int len;
    int plen;

    len = ft_strlen(cmd);
    plen = ft_strlen(info->term->prompt);
    ft_putstr(info->term->capa->str_cd);
    ft_putstr(&info->term->cmd[info->term->pos_c - 1]);
    move_cursor(info->term->capa, len, plen, info->term->pos_c);
    return (1);
}
