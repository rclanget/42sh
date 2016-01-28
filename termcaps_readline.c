/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:16:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/28 23:22:07 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "command_line_termcaps.h"

#include <unistd.h>

char        *getnextline(int fd, t_info *info)
{
    char    *line;
    int     ret;

    line = NULL;
    ret = get_next_line(0, &line);
    return (ret ? line : NULL);
}

char        *termcaps_readline(t_info *info)
{
    int     term;

    if (isatty(0))
    {
        term = termcaps_activation(info->term->is_term);
        ft_putstr(info->term->prompt);
        return ((term) ? termcaps_loop(info) : getnextline(0, info));
    }
    else
    {
        return (getnextline(0, info));
    }
    return (NULL);
}
