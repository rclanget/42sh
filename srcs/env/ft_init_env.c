/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 19:15:24 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 12:27:28 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "env.h"
#include "libft.h"

char	**split_env_var(char *line)
{
	char	**tab;
	char	*tmp;
	int		len;

	tab = (char **)malloc(sizeof(char *) * 3);
	tmp = ft_strchr(line, '=');
	tab[0] = ft_strsub(line, 0, tmp - line);
	len = ft_strlen(line) - (tmp - line);
	tab[1] = ft_strsub(line, tmp - line + 1, len - 1);
	tab[2] = 0;
	return (tab);
}

t_env	*ft_savenv(char **tab)
{
	t_env	*elem;
	char	**tmp;

	elem = NULL;
	if (tab && *tab)
	{
		elem = (t_env *)malloc(sizeof(t_env));
		tmp = split_env_var(*tab);
		elem->var = tmp[0];
		elem->content = tmp[1];
		free(tmp);
		elem->next = ft_savenv(++tab);
	}
	return (elem);
}

void	ft_free_env(t_env *env)
{
	if (env)
	{
		ft_free_env(env->next);
		free(env->var);
		free(env->content);
		free(env);
	}
}

void	ft_init_env(t_info *info, char **env)
{
	info->env = ft_savenv(env);
}
