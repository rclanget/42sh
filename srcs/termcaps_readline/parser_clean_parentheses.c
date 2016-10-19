/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clean_parentheses.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:49:27 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/18 16:49:32 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

char	*clean_parentheses(char *str, int *value)
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
			ft_memcpy(str_new,  str + 1, i - 1);
			*value = PARENTHESES_VAL;
			free(str);
			return (str_new);
		}
	}
	return (str);
}