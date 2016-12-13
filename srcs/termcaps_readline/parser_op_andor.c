/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_andor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:56:41 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/13 18:10:27 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "tools.h"

int			check_op_and(char *str)
{
	char	*tmp;
	int		pos1;
	int		pos2;

	tmp = ft_strrstr_custom(str, "&&");
	pos1 = ft_strlen(tmp);
	tmp = ft_strrstr_custom(str, "||");
	pos2 = ft_strlen(tmp);
	if (pos1 && pos2)
		return (pos1 > pos2 ? 3 : 2);
	else if (pos1)
		return (2);
	else if (pos2)
		return (3);
	return (0);
}

char		**parse_op_and(char *str, int pos)
{
	char	**tab;
	char	*tmp;

	tab = NULL;
	tmp = ft_strrstr_custom(str, "&&");
	pos = tmp - str;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup("&&");
		tab[2] = ft_strdup(&str[pos + 2]);
		tab[3] = NULL;
	}
	return (tab);
}

int			check_op_or(char *str)
{
	return (check_op_and(str));
}

char		**parse_op_or(char *str, int pos)
{
	char	**tab;
	char	*tmp;

	tab = NULL;
	tmp = ft_strrstr_custom(str, "||");
	pos = tmp - str;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup("||");
		tab[2] = ft_strdup(&str[pos + 2]);
		tab[3] = NULL;
	}
	return (tab);
}
