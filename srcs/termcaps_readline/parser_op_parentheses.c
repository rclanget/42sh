/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_parentheses.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:31:19 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 16:08:33 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int			check_op_parentheses(char *str)
{
	return ((*str == '(') ? 1 : 0);
}

static char	*subshell_value(char *str, int *pos)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	while (str[++i] && str[i] != ')' && str[i - 1] != '\\')
		;
	if (str[i] == ')' && i > 1)
	{
		value = ft_memalloc(i);
		ft_memcpy(value, str + 1, i - 1);
	}
	*pos += i;
	return (value);
}

char		**parse_op_parentheses(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[1] = subshell_value(&str[pos], &pos);
		tab[0] = ft_strdup(&str[pos + 1]);
		tab[2] = NULL;
		tab[3] = NULL;
	}
	return (tab);
}
