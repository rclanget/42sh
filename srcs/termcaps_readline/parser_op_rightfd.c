/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_rightfd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:47:19 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/24 16:20:51 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int			check_op_rightfd(char *str)
{
	char	*tmp;

	tmp = str;
	if (*str == ' ' && ++str)
	{
		while (ft_isdigit(*str))
			++str;
		if (*str == '>')
		{
			++str;
			if (*str == '&')
				++str;
		}
	}
	return (((str - tmp) > 1) ? 1 : 0);
}

char		**parse_op_rightfd(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup(">>");
		tab[2] = ft_strdup(&str[pos + 2]);
		tab[3] = NULL;
	}
	return (tab);
}
