/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clean_parentheses.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:49:27 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/05 17:41:28 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_tree	*clean_parentheses(t_tree *node, char *str)
{
	int		i;
	char	*str_new;

	i = 0;
	str_new = NULL;
	if (str[i] == '(')
	{
		while (str[++i] && str[i] != ')' && str[i - 1] != '\\')
			;
		if (str[i] == ')' && str[i - 1] != '\\')
		{
			str_new = ft_memalloc(i);
			node->elem = ft_memcpy(str_new, str + 1, i - 1);
			node->type = PARENTHESES_VAL;
			free(str);
			node->left = parser_cmd(ft_strtrim(node->elem));
			return (node);
		}
	}
	else
		node->elem = str;
	return (node);
}
