/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:55:39 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/25 17:24:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *clean_backslash(char *str)
{
	int	 i;
	int	 j;
	char	 *str_new;

	i = 0;
	j = 0;
	while (str[j++])
		if (str[j] != '\\')
			i++;
	if ((str_new = ft_memalloc(i)))
	{
		j = 0;
		i = 0;
		while (str[j])
		{
			if (str[j] != '\\')
				str_new[i++] = str[j++];
			else
				j++;
		}
		str_new[i] = 0;
		free(str);
	}
	return (str_new);
}
