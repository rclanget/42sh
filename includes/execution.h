/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:30:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/15 20:06:54 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "shell.h"
# include "alias_struct.h"

int			execution_motor(t_info *info, t_tree *cmd, int wait);
int			execution_command(t_info *info, t_tree *cmd, int wait);
int			execution_status(int status);
char		*lire_hashmap(t_hashmap *hashmap, char *key);

t_tree		*self_node(t_info *info);

t_word		*get_magicquotelist(char *s);
char		*make_sentence(t_word *words);
char		*apply_magicquote(t_info *info, char *str);
char		*process_magicquote(t_info *info, char *cmd);
t_word		*treat_magicquote(t_info *info, t_word *words);

char		**redirection_agreg(char **cmd);
int			is_redirection_agreg(char **cmd, int i);

char		*check_dollard_parenthese(char *cmd);

char		*replace_tild(t_info *info, char *command, int pos);
int			find_tild(char *cmd);
void		init_assignation_localvar(int *i, char *quote, char *d_quote);
void		change_state(char *quote);

#endif
