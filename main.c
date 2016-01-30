/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:57:22 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/30 15:57:19 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <termcap.h>

int termcap_available(void)
{
    int     ret;
    char    *term;

    ret = 0;
    if ((term = ft_getenv("TERM")))
    {
        if ((tgetent(NULL, term) > 0))
            ++ret;
        free(term);
    }
    return (ret);
}

int main(int argc, char const *argv[]) {
    t_info info;
    t_termcaps term;

    ft_bzero(&info, sizeof(info));
    ft_bzero(&term, sizeof(term));

    info.term = &term;
    info.term->is_term = termcap_available();
    info.term->capa = termcap_capainit();
    info.term->cmd = ft_memalloc(BUFFER_SIZE);
    // info.term->prompt = NULL;

    char *command;
    while ((command = termcaps_readline(&info)))
    {
        ft_print("%s\n", command);
        if (info.term->is_term)
            ft_bzero(info.term->cmd, BUFFER_SIZE);
        else
            free(command);
        info.term->pos_c = 0;
    }
    return 0;
}
