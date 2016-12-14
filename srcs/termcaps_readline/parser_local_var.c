/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_local_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:49:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/11 16:17:00 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "parser.h"

char		**my_ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*to_find;

	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(*tab) * (2 + 1));
	if (!tab)
		return (NULL);
	tab[2] = 0;
	to_find = ft_strchr(s, c);
	tab[0] = ft_strsub(s, 0, diff_address(to_find, s));
	tab[1] = ft_strsub(s, diff_address(to_find, s) + 1, ft_strlen(s));
	return (tab);
}

void		init_assignation_localvar(int *i, char *quote, char *d_quote)
{
	*i = 0;
	*quote = '0';
	*d_quote = '0';
}

void		change_state(char *quote)
{
	if (*quote == '0')
		*quote = '1';
	else
		*quote = '0';
}

int			is_assignation_localvar(char *cmd)
{
	int		i;
	char	quote;
	char	d_quote;

	init_assignation_localvar(&i, &quote, &d_quote);
	if ((cmd[i] == '(' && cmd[i] == '`') || !(ft_str_isalnum_spe(cmd)))
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '"')
			change_state(&d_quote);
		else if (cmd[i] == '\'')
			change_state(&quote);
		if (cmd[i - 1] && cmd[i] == '=' && quote == '0' &&\
			d_quote == '0' && ft_isalnum(cmd[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

t_tree		*parser_local_var(char *cmd, t_tree *node)
{
	char	**tab;
	t_tree	*node_left;
	t_tree	*node_right;

	node_left = (t_tree *)ft_memalloc(sizeof(t_tree));
	ft_bzero(node, sizeof(t_tree));
	node_right = (t_tree *)ft_memalloc(sizeof(t_tree));
	ft_bzero(node, sizeof(t_tree));
	tab = my_ft_strsplit(cmd, '=');
	node->type = 10;
	node->elem = ft_strdup("=");
	node_left->elem = ft_strdup(tab[0]);
	node_right->elem = ft_strdup(tab[1]);
	node->left = node_left;
	node->right = node_right;
	free_tab(tab);
	return (node);
}