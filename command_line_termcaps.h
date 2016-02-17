/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_termcaps.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:51:24 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/18 00:02:16 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define     BUFFER_SIZE     1024
#define     NL              10
#define     CTRL_D          4

typedef struct          s_info
{
    struct s_termcaps   *term;
    int                 stop;
}                       t_info;

typedef struct          s_termcaps
{
    int                 is_term;
    struct s_capa       *capa;
    char                *prompt;
    char                *cmd;
    char                *save_cmd;
    int                 pos_c;
}                       t_termcaps;

typedef struct          s_key
{
    long                key;
    void                (*f)(t_info *info);
}                       t_key;

typedef struct          s_capa
{
    int                 flg_os;
    int                 flg_eo;
    char                *str_dc;
    char                *str_cl;
    char                *str_do;
    char                *str_up;
    char                *str_le;
    char                *str_ri;
    char                *str_ce;
    char                *str_cd;
    char                *str_bl;
    char                *str_ho;
}                       t_capa;

void		move_cursor_left(t_info *info);
void		move_cursor_right(t_info *info);
void		move_start(t_info *info);
void		move_end(t_info *info);
void		move_delete(t_info *info);
void		move_supp(t_info *info);
void		move_clear_left(t_info *info);
void		move_clear_right(t_info *info);
void		move_clear_screen(t_info *info);
void		move_line_up(t_info *info);
void		move_line_down(t_info *info);
void		move_word_left(t_info *info);
void		move_word_right(t_info *info);
void		cut_line(t_info *info);
void		copy_line(t_info *info);
void		paste_line(t_info *info);

void        move_cursor(t_capa *capa, int from, int plen, int to);

int         termcaps_save(int save_or_restore);

char        *ft_getenv(char *var);
char        *termcaps_readline(t_info *info);
char        *termcaps_loop(t_info *info);
int         termcaps_activation(int is_term);
int         termcaps_handle_keyboard(t_info *info, long chr);
int         termcaps_print(t_info *info, char *cmd, long chr);
t_capa      *termcap_capainit(void);
int         termcap_winsz_x(void);
int         termcap_winsz_y(void);
