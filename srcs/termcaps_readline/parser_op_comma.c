/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_comma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:20:44 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/07 22:41:06 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int			check_op_comma(char *str)
{
	return ((str && *str && *str == ';') ? 1 : 0);
}

char		**parse_op_comma(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)ft_memalloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup(";");
		tab[2] = ft_strdup(&str[pos + 1]);
		tab[3] = NULL;
	}
	return (tab);
}
