/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:00:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/22 23:39:46 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "shell.h"

# define MAX_BUILTIN		13

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
int				builtin_read(t_info * info, t_tree *cmd);
int				builtin_unset(t_info *info, t_tree *cmd);
int				builtin_export(t_info *info, t_tree *cmd);

int				is_builtin(char *cmd);
int				execution_builtin(t_info *info, t_tree *cmd);

#endif
