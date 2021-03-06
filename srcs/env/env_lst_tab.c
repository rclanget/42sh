/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 16:15:34 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/08 17:53:23 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "tools.h"

#include <stdlib.h>

void	transfer_env(char **tab, t_env *env, int i)
{
	char	*tmp;

	if (env)
	{
		tmp = ft_strjoin_custom(env->var, "=");
		tab[i] = ft_strjoin_custom(tmp, env->content);
		free(tmp);
		transfer_env(tab, env->next, ++i);
	}
	else
		tab[i] = 0;
}

char	**env_lst_tab(t_env *env)
{
	t_env	*cpy;
	int		i;
	char	**tab;

	i = 0;
	cpy = env;
	tab = NULL;
	while (cpy && ++i && (cpy = cpy->next))
		;
	if (i)
	{
		tab = (char **)malloc(sizeof(char *) * (i + 1));
		transfer_env(tab, env, 0);
	}
	return (tab);
}

void	free_env_tab(char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
			free(env[i++]);
		free(env);
	}
}
