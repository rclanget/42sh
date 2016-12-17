/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clean_parentheses.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:49:27 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/16 23:47:08 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "parser.h"

static int	isquote(char c)
{
	static	int backslash = 0;
	static	int quote = 0;
	static	int dquote = 0;
	static	int mquote = 0;

	if (c == '\'' && !backslash && !dquote && !mquote)
		quote = !quote;
	else if (c == '\"' && !backslash && !quote && !mquote)
		dquote = !dquote;
	else if (c == '`' && !backslash && !dquote && !quote)
		mquote = !mquote;
	else if (c == '\\' && !quote)
		backslash = !backslash;
	return (quote || backslash || dquote || mquote);
}

int			get_close_parenthese(char *str, int i)
{
	int		open_parenthese;

	open_parenthese = 0;
	while (str[i])
	{
		if (!isquote(str[i]))
		{
			if (str[i] == '(')
				open_parenthese++;
			else if (str[i] == ')')
				if (!--open_parenthese)
					break ;
		}
		i++;
	}
	return (i);
}

t_tree		*clean_parentheses(t_tree *node, char *str)
{
	int		i;
	char	*str_new;

	i = 0;
	str_new = NULL;
	if (str && str[i] == '(')
	{
		i = get_close_parenthese(str, i);
		if (str[i] == ')' && str[i - 1] != '\\')
		{
			str_new = ft_strndup(str + 1, i - 1);
			node->elem = ft_strtrim(str_new);
			node->type = PARENTHESES_VAL;
			ft_free_them_all(2, &str, &str_new);
			node->left = parser_cmd(ft_strtrim(node->elem));
			return (node);
		}
	}
	else
		node->elem = str;
	return (node);
}
