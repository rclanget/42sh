/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_termcaps.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:51:24 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/28 10:36:20 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LINE_TERMCAPS_H
# define COMMAND_LINE_TERMCAPS_H

# define BUFFER_SIZE     1024
# define NL              10
# define CTRL_D          4

# include "shell.h"

typedef struct	s_key
{
	long		key;
	void		(*f)(struct s_info *info);
}				t_key;

char			*ft_getenv(char *var);

int				termcap_available(void);
int				termcaps_save(int save_or_restore);
int				termcaps_activation(int is_term);
t_capa			*termcap_capainit(void);

char			*termcaps_readline(t_info *info);
char			*termcaps_loop(t_info *info);
int				termcaps_handle_keyboard(t_info *info, long chr);
int				termcaps_print(t_info *info, char *cmd, long chr);
int				termcap_winsz_x(void);
int				termcap_winsz_y(void);

void			move_cursor(t_capa *capa, int from, int plen, int to);

void			move_cursor_left(t_info *info);
void			move_cursor_right(t_info *info);

void			move_start(t_info *info);
void			move_end(t_info *info);
void			move_delete(t_info *info);

void			move_supp(t_info *info);

void			move_clear_left(t_info *info);
void			move_clear_right(t_info *info);

void			move_clear_screen(t_info *info);

void			move_line_up(t_info *info);
void			move_line_down(t_info *info);

void			move_word_left(t_info *info);
void			move_word_right(t_info *info);

void			cut_line(t_info *info);
void			copy_line(t_info *info);
void			paste_line(t_info *info);
char			*get_selection(t_info *info);

void			move_up(t_info *info);
void			move_down(t_info *info);

void			reverse_search_i(t_info *info);

#endif
