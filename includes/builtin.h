/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:00:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/21 18:01:41 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "shell.h"

# define MAX_BUILTIN		10

typedef struct	s_builtin
{
	char		*name;
	int			(*func)(t_info *info, t_tree *cmd);
}				t_builtin;

int				builtin_cd(t_info *info, t_tree *cmd);
int				builtin_echo(t_info *info, t_tree *cmd);
int				builtin_setenv(t_info *info, t_tree *cmd);
int				builtin_unsetenv(t_info *info, t_tree *cmd);
int				builtin_alias(t_info *info, t_tree *cmd);
int				builtin_unalias(t_info *info, t_tree *cmd);
int				builtin_env(t_info *info, t_tree *cmd);
int				builtin_history(t_info *info, t_tree *cmd);
int				builtin_exit(t_info *info, t_tree *cmd);
int				builtin_false(t_info * info, t_tree *cmd);
int				builtin_true(t_info * info, t_tree *cmd);

int				is_builtin(char *cmd);
int				execution_builtin(t_info *info, t_tree *cmd);

#endif
