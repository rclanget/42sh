/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:59:07 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/07 17:49:54 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"

void    keyboard_clear_line(t_info *info)
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
        write(1, "\n", ((plen + len) % termcap_winsz_x()) ? 0 : 1);
        move_cursor(term->capa, len , plen, 0);
        term->pos_c = 0;
    }
    else
        ft_putstr(term->capa->str_bl);
}

void    keyboard_clear_screen(t_info *info)
{
    ft_putstr(info->term->capa->str_ho);
    ft_putstr(info->term->capa->str_cd);
    ft_putstr(info->term->prompt);
    ft_bzero(info->term->cmd, BUFFER_SIZE);
    info->term->pos_c = 0;
}
