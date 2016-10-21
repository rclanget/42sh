/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:54:59 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/21 14:36:19 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int			check_op_left(char *str)
{
	return ((*str == '<' && *(str + 1) && *(str + 1) != '<') ? 6 : 0);
}

char		**parse_op_left(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup("<");
		tab[2] = ft_strdup(&str[pos + 1]);
		tab[3] = NULL;
	}
	return (tab);
}

int			check_op_dleft(char *str)
{
	return ((!ft_strncmp(str, "<<", 2)) ? 8 : 0);
}

char		**parse_op_dleft(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = ft_strndup(str, pos);
		tab[1] = ft_strdup("<<");
		tab[2] = ft_strdup(&str[pos + 2]);
		tab[3] = NULL;
	}
	return (tab);
}
