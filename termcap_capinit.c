/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_capinit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:57:06 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/05 15:58:40 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

#include <termcap.h>
#include <stdlib.h>

t_capa *termcap_capainit(void)
{
    t_capa  *capa;

    capa = NULL;
    if ((capa = malloc(sizeof(*capa))))
    {
        capa->str_os = tgetstr("os", NULL);
        capa->str_eo = tgetstr("eo", NULL);
        capa->str_dc = tgetstr("dc", NULL);
        capa->str_cl = tgetstr("cl", NULL);
        capa->str_do = tgetstr("do", NULL);
        capa->str_up = tgetstr("up", NULL);
        capa->str_le = tgetstr("le", NULL);
        capa->str_ri = tgetstr("nd", NULL);
        capa->str_ce = tgetstr("ce", NULL);
        capa->str_cd = tgetstr("cd", NULL);
        capa->str_bl = tgetstr("bl", NULL);
    }
    return (capa);
}
