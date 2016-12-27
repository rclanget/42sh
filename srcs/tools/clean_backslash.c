/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:55:39 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/26 14:15:12 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(char *str, int quote)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (str[++j])
	{
		if (str[j] != '\\' || quote)
			i++;
		else if (str[j] == '\\' && str[j + 1] == '\\' && ++j)
			i += quote ? 2 : 1;
	}
	return (i);
}

char			*clean_backslash(char *str, char quote)
{
	int		i;
	int		j;
	char	*str_new;

	j = 0;
	i = 0;
	(void)quote;
	if ((str_new = ft_memalloc(get_len(str, quote == '\'') + 1)))
	{
		while (str[j])
		{
			if (str[j] != '\\' || (str[j] == '\\' && quote == '\''))
				str_new[i++] = str[j++];
			else if (str[j] == '\\' && str[j + 1] == '\\' && ++j)
				str_new[i++] = str[j++];
			else
				j++;
		}
		str_new[i] = 0;
		free(str);
	}
	return (str_new ? str_new : str);
}
