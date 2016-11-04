/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:43:54 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 13:01:51 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_STRUCT_H
# define TERMCAPS_STRUCT_H

# include "shell.h"

typedef struct			s_termcaps
{
	int					is_term;
	struct s_capa		*capa;
	char				*prompt;
	char				*cmd;
	char				*save_cmd;
	int					pos_c;
}						t_termcaps;

typedef struct			s_capa
{
	int					flg_os;
	int					flg_eo;
	char				*str_dc;
	char				*str_cl;
	char				*str_do;
	char				*str_up;
	char				*str_le;
	char				*str_ri;
	char				*str_ce;
	char				*str_cd;
	char				*str_bl;
	char				*str_ho;
	char				*str_us;
	char				*str_ue;
}						t_capa;

#endif
