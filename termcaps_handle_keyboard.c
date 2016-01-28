/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_handle_keyboard.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 00:19:56 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/28 23:07:19 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

int add_chr(t_info *info, long chr)
{
   int cmd_len;
   int i;

   if (ft_isprint(chr))
   {
       cmd_len = ft_strlen(info->term->cmd);
       i = cmd_len - info->term->pos_c;
       if (cmd_len < BUFFER_SIZE)
       {
           info->term->cmd[cmd_len + 1] = 0;
           while (i >= 0 && info->term->cmd[info->term->pos_c])
               info->term->cmd[info->term->pos_c + i + 1] = info->term->cmd[info->term->pos_c + i--];
           info->term->cmd[info->term->pos_c] = chr;
           ++info->term->pos_c;
       }
       return (1);
   }
   return (0);
}

int     termcaps_handle_keyboard(t_info *info, long chr)
{
    int      i;

    i = -1;
    // while (g_key_tab[++i])
    // {
    //    if (g_key_tab[i].key == chr)
    //        return (g_key_tab[i].f(info));
    // }
    add_chr(info, chr);
    return (termcaps_print(info, info->term->cmd));
}
