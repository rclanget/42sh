/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:30:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/26 15:31:42 by rclanget         ###   ########.fr       */
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
char		*apply_magicquote(t_info *info, char *str, int type);
char		*process_magicquote(t_info *info, char *cmd);
t_word		*treat_magicquote(t_info *info, t_word *words);

char		**redirection_agreg(char **cmd);
int			is_redirection_agreg(char **cmd, int i);

char		*check_dollard_parenthese(char *cmd);

char		*ft_execution_error_msg(char *cmd);

#endif
