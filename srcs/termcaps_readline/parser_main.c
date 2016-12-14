/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:49:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/14 14:24:56 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

#define BCKSLSH 0
#define SQTE 1
#define DQTE 2
#define MQTE 3
#define SUBSHL 4

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
	int		d[5];

	ft_bzero(d, sizeof(int) * 5);
	if (cmd[i] == '(')
	{
		while (cmd[++i])
		{
			if (cmd[i] == '(')
				d[SUBSHL]++;
			if (cmd[i] == '\'' && !d[BCKSLSH] && !d[DQTE] && !d[MQTE])
				d[SQTE] = !d[SQTE];
			else if (cmd[i] == '\"' && !d[BCKSLSH] && !d[SQTE] && !d[MQTE])
				d[DQTE] = !d[DQTE];
			else if (cmd[i] == '`' && !d[BCKSLSH] && !d[DQTE] && !d[SQTE])
				d[MQTE] = !d[MQTE];
			else if (cmd[i] == '\\' && !d[SQTE])
				d[BCKSLSH] = !d[BCKSLSH];
			else if (!(d[SQTE] || d[BCKSLSH] || d[DQTE] || d[MQTE])
				&& cmd[i] == ')' && cmd[i - 1] != '\\' && !d[SUBSHL]--)
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
