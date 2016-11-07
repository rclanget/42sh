/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:49:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/05 19:57:49 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

static void	free_tab(char **tab)
{
	int		i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		free(tab[i]);
		free(tab);
	}
}

int			pass_string(char *cmd, int i)
{
	char	c;
	int		ret;

	if (cmd[i] == '\\')
	{
		ret = ++i;
	}
	else
	{
		c = cmd[i++];
		while (cmd[i] != c)
		{
			if (cmd[i] == '\\')
			{
				;
			}
			++i;
		}
		ret = i;
	}
	return (ret);
}

int			pass_grouping(char *cmd, int i)
{
	char	c;

	if (cmd[i] == '(')
	{
		c = ')';
		while (cmd[++i] && cmd[i] != c && cmd[i - 1] != '\\');
	}
	return (i);
}

char		**split_on_highest(char *cmd, int *type)
{
	int		i;
	int		j;
	char	**tab;

	j = -1;
	*type = 0;
	tab = NULL;
	if (cmd)
	{
		while (g_parse[++j].check)
		{
			i = 0;
			while (cmd[i] && !tab)
			{
				if (cmd[i] == '\"' || cmd[i] == '\'' || cmd[i] == '\\')
					i = pass_string(cmd, i);
				else if (cmd[i] == '(')
					i = pass_grouping(cmd, i);
				else if (!ft_strncmp(">&", &cmd[i], 2) || !ft_strncmp("<&", &cmd[i], 2))
					i += 2;
				else if ((*type = check_hightest(&cmd[i], j)))
					tab = split_on(cmd, &cmd[i] - cmd, *type);
				++i;
			}
		}
	}
	return (tab);
}

t_tree		*parser_cmd(char *cmd)
{
	t_tree	*node;
	char	**tab;
	int		type;

	node = NULL;
	if (cmd && ft_strlen(cmd))
	{
		node = (t_tree *)ft_memalloc(sizeof(t_tree));
		ft_bzero(node, sizeof(t_tree));
		if ((tab = split_on_highest(cmd, &type)))
		{
			node->type = type;
			node->elem = ft_strdup(tab[1]);
			node->left = parser_cmd(ft_strtrim(tab[0]));
			node->right = parser_cmd(ft_strtrim(tab[2]));
			free_tab(tab);
		}
		else
			node->elem = clean_parentheses(ft_strdup(cmd), &node->type);
	}
	free(cmd);
	return (node);
}
