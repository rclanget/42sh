/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:55:04 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/24 16:21:42 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int			check_op_right(char *str)
{
	return ((*str == '>' && *(str + 1) && *(str + 1) != '>') ? 1 : 0);
}

char		**parse_op_right(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup(">");
		tab[2] = ft_strdup(&str[pos + 1]);
		tab[3] = NULL;
	}
	return (tab);
}

int			check_op_dright(char *str)
{
	return ((!ft_strncmp(str, ">>", 2)) ? 1 : 0);
}

char		**parse_op_dright(char *str, int pos)
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
