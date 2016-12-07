/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_split_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:29 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

static size_t	ft_count(char const *s, int (*func)(int))
{
	int		i;
	int		j;
	int		w;

	i = 0;
	w = 1;
	while (0 != *(s + i))
	{
		while (true == func(*(s + i)))
			++i;
		j = i;
		while (0 != *(s + i) && false == func(*(s + i)))
			++i;
		if (i != j)
			++w;
	}
	return (w);
}

char			**ft_tiny_split_func(char const *s, int (*func)(int))
{
	char	**tab;
	int		i;
	int		j;
	int		w;

	if (0 != (tab = (char **)malloc(sizeof(char *) * ft_count(s, func))))
	{
		i = 0;
		w = 0;
		while (0 != *(s + i))
		{
			while (true == func(*(s + i)))
				++i;
			j = i;
			while (0 != *(s + i) && false == func(*(s + i)))
				++i;
			if (i != j)
				*(tab + w++) = ft_tiny_strndup(s + j, i - j);
		}
		*(tab + w) = 0;
	}
	return (tab);
}
