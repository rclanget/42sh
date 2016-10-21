/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_andor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:56:41 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/21 14:35:10 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int			check_op_and(char *str)
{
	return ((!ft_strncmp(str, "&&", 2)) ? 2 : 0);
}

char		**parse_op_and(char *str, int pos)
{
	char	**tab;

	tab = NULL;
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
	return ((!ft_strncmp(str, "||", 2)) ? 3 : 0);
}

char		**parse_op_or(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup("||");
		tab[2] = ft_strdup(&str[pos + 2]);
		tab[3] = NULL;
	}
	return (tab);
}
