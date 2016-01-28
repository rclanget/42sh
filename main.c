/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:57:22 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/29 00:24:56 by ulefebvr         ###   ########.fr       */
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

t_capa *termcap_capainit(void)
{
    t_capa  *capa;

    capa = NULL;
    if ((capa = malloc(sizeof(*capa))))
    {
        capa->str_dc = tgetstr("dc", NULL);
        capa->str_cl = tgetstr("cl", NULL);
        capa->str_do = tgetstr("do", NULL);
        capa->str_up = tgetstr("up", NULL);
        capa->str_le = tgetstr("le", NULL);
        capa->str_ri = tgetstr("nd", NULL);
        capa->str_ce = tgetstr("ce", NULL);
        capa->str_cd = tgetstr("cd", NULL);
        capa->str_sc = tgetstr("sc", NULL);
        capa->str_rc = tgetstr("rc", NULL);
    }
    return (capa);
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

    ft_print("yolo\n");

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
