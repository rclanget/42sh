/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:30:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/06 18:32:44 by ulefebvr         ###   ########.fr       */
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
void		apply_fd_agreg(t_tree *cmd);

#endif
