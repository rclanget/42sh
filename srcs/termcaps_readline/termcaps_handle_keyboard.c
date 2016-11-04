/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_handle_keyboard.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 00:19:56 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/04 15:24:49 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "keyboard_keys.h"
#include "libft.h"

#include <unistd.h>

static t_key g_key_tab[] =
{
  {MYKEY_RIGHT, move_cursor_right},
  {MYKEY_LEFT, move_cursor_left},
  {CTRL_A, move_start},
  {KEY_START, move_start},
  {CTRL_E, move_end},
  {KEY_END, move_end},
  {KEY_DEL, move_delete},
  {KEY_SUPP, move_supp},
  {CTRL_U, move_clear_left},
  {CTRL_K, move_clear_right},
  {CTRL_L, move_clear_screen},
  {CTRL_UP, move_line_up},
  {CTRL_DOWN, move_line_down},
  {CTRL_RIGHT, move_word_right},
  {CTRL_LEFT, move_word_left},
  {CTRL_I, cut_line},
  {CTRL_O, copy_line},
  {CTRL_P, paste_line},
  {KEY_UP, move_up},
  {KEY_DOWN, move_down},
  {CTRL_R, reverse_search_i}
};

static int     add_chr(t_info *info, long chr)
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
          {
              info->term->cmd[info->term->pos_c + i + 1] = info->term->cmd[info->term->pos_c + i];
              --i;
          }
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
    while (++i < 21)
    {
       if (g_key_tab[i].key == chr)
       {
           g_key_tab[i].f(info);
           return (1);
       }
    }
    if (!(ret = add_chr(info, chr)))
        return (0);
    return (termcaps_print(info, info->term->cmd, chr));
}
