/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:55:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/22 17:40:36 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H

# include "shell.h"
# include "alias_struct.h"

void		add_alias(t_info *info, char *var, char *content);
void		remove_alias(t_info *info, char *var);
t_alias		*search_alias(t_info *info, char *var);
void		update_alias(t_info *info, char *init, char *replace);
char		*check_alias(t_info *info, char *init);

char 		*get_other(char *cmd, int *code);
char 		*get_command(char *cmd, int *code);
t_word		*get_the_list(char *s);

t_alias		*search_alias2(t_info *info, char *var, int *position);
char		*make_sentence(t_word *words);
char		*apply_alias(t_info *info, t_word *ws, char *cmd, char *visited);
#endif
