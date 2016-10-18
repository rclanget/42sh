/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 14:39:06 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 15:30:44 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "env.h"
#include "tools.h"
#include "execution.h"
#include "libft.h"

void	*free_tab(char **tab)
{
	int i;

	i = -1;
	if (!tab)
		return (NULL);
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

void        print_env(t_env *env)
{
    while (env)
    {
        ft_print("%s=%s\n", env->var, env->content);
        env = env->next;
    }
}

t_env       *cpy_env(t_env *env)
{
    t_env   *tmp;
    char    **cpy;

    tmp = NULL;
    cpy = NULL;
    if ((cpy = env_lst_tab(env)))
    {
        tmp = ft_savenv(cpy);
        free_tab(cpy);
    }
    return (tmp);
}

int         ft_takechanges(t_info *info, char **argv)
{
    char    **tmp;
    int     i;

    i = 0;
    if (argv && argv[i] && !ft_strcmp(argv[i], "-i"))
    {
        ft_free_env(info->env);
        info->env = NULL;
        ++i;
    }
    while (argv && argv[i] && ft_strchr(argv[i], '='))
    {
        tmp = split_env_var(argv[i]);
        env_update_var(info, tmp[0], tmp[1]);
        free_tab(tmp);
        i++;
    }
    return (i);
}

int         builtin_env(t_info *info, t_tree *cmd)
{
    int     len;
    t_env   *tmp;
    char    **argv;
    char    **tmp_comm;

    tmp = info->env;
    len = ft_tablen(cmd->cmd);
    info->env = cpy_env(info->env);
    argv = cmd->cmd + 1;
    tmp_comm = cmd->cmd;
    if (!(argv += ft_takechanges(info, argv)) || !*argv)
        print_env(info->env);
    else
    {
        cmd->cmd = argv;
        execution_command(info, cmd, 1);
        cmd->cmd = tmp_comm;
    }
    ft_free_env(info->env);
    info->env = tmp;
    return (0);
}
