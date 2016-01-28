/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_termcaps.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:51:24 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/28 22:58:19 by ulefebvr         ###   ########.fr       */
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
    int                 init_x;
    int                 init_y;
    int                 x;
    int                 y;
    int                 pos_c;
}                       t_termcaps;

typedef struct          s_key
{
    long                key;
    void                (*f)(t_info *info);
}                       t_key;

typedef struct          s_capa
{
    char                *str_dc;
    char                *str_cl;
    char                *str_do;
    char                *str_up;
    char                *str_le;
    char                *str_ri;
    char                *str_ce;
    char                *str_cd;
    char                *str_sc;
    char                *str_rc;
}                       t_capa;

// t_key g_key_tab[] = {{key, function}};

char        *ft_getenv(char *var);
char        *termcaps_readline(t_info *info);
char        *termcaps_loop(t_info *info);
int         termcaps_activation(int is_term);
int         termcaps_handle_keyboard(t_info *info, long chr);
int         termcaps_print(t_info *info, char *cmd);
