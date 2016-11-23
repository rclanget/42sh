/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:18:50 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 16:02:52 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "env_struct.h"

void		ft_init_env(t_info *info, char **env);

t_env		*ft_savenv(char **tab);

void		env_add_var(t_info *info, char *var, char *content);
void		env_remove_var(t_info *info, char *var);
void		env_update_var(t_info *info, char *var, char *content);

char		**env_lst_tab(t_env *env);
char		**split_env_var(char *line);
void		free_env_tab(char **env);
t_env		*search_env_var(t_info *info, char *var);

void		transfer_env(char **tab, t_env *env, int i);

void		update_path(t_info *info, t_env *path);

void		ft_free_env(t_env *env);

void		*free_tab(char **tab);

#endif
