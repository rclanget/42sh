/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_handle_keyboard.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 00:19:56 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/04 23:33:53 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "keyboard_keys.h"

t_key g_key_tab[] =
{
  {MYKEY_RIGHT, move_cursor_right},
  {MYKEY_LEFT, move_cursor_left}
};

int add_chr(t_info *info, long chr)
{
  int cmd_len;
  int i;
  int ret;

  ret = 0;
  if (ft_isprint(chr))
  {
      cmd_len = ft_strlen(info->term->cmd);
      i = cmd_len - info->term->pos_c;
      ret = (i == 0) ? 1 : 2;
      if (cmd_len < BUFFER_SIZE)
      {
          info->term->cmd[cmd_len + 1] = 0;
          while (i >= 0 && info->term->cmd[info->term->pos_c])
              info->term->cmd[info->term->pos_c + i + 1] = info->term->cmd[info->term->pos_c + i--];
          info->term->cmd[info->term->pos_c] = chr;
          ++info->term->pos_c;
      }
  }
  return (ret);
}

int     termcaps_handle_keyboard(t_info *info, long chr)
{
    int         i;
    int         ret;

    i = -1;
    while (++i < 2)
    {
       if (g_key_tab[i].key == chr)
       {
           g_key_tab[i].f(info);
           return (1);
       }
    }
    if (!(ret = add_chr(info, chr)))
        return (0);
    return (termcaps_print(info, info->term->cmd));
}
