/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:49:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/11 16:17:00 by rclanget         ###   ########.fr       */
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

	ret = i;
	if (cmd[i] == '\\')
		++ret;
	else if ((c = cmd[i]) && cmd[i + 1])
	{
		while (cmd[++i] && cmd[i] != c)
		{
			if (cmd[i] == '\\')
			{
				;
			}
		}
		ret = i;
	}
	return (ret);
}

int			pass_grouping(char *cmd, int i)
{
	static	int backslash = 0;
	static	int quote = 0;
	static	int dquote = 0;
	static	int mquote = 0;

	if (cmd[i] == '(')
	{
		while (cmd[++i])
		{
			if (cmd[i] == '\'' && !backslash && !dquote && !mquote)
				quote = !quote;
			else if (cmd[i] == '\"' && !backslash && !quote && !mquote)
				dquote = !dquote;
			else if (cmd[i] == '`' && !backslash && !dquote && !quote)
				mquote = !mquote;
			else if (cmd[i] == '\\' && !quote)
				backslash = !backslash;
			else if (!(quote || backslash || dquote || mquote)
				&& cmd[i] == ')' && cmd[i - 1] != '\\')
				break ;
		}
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
	while (cmd && g_parse[++j].check)
	{
		i = -1;
		while ((i == -1 || cmd[i]) && cmd[++i] && !tab)
		{
			if (cmd[i] == '\"' || cmd[i] == '\'' || cmd[i] == '\\' ||\
				cmd[i] == '`')
				i = pass_string(cmd, i);
			else if (cmd[i] == '(')
				i = pass_grouping(cmd, i);
			else if (!ft_strncmp(">&", &cmd[i], 2)
				|| !ft_strncmp("<&", &cmd[i], 2))
				i += 2;
			else if ((*type = check_hightest(&cmd[i], j)))
				tab = split_on(cmd, &cmd[i] - cmd, *type);
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
		else if (is_assignation_localvar(cmd))
			node = parser_local_var(cmd, node);
		else
			node = clean_parentheses(node, ft_strdup(cmd));
	}
	free(cmd);
	return (node);
}
