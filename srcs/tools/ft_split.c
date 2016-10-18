/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:32:19 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/23 17:38:17 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_words(char *s)
{
	int		i;

	i = 0;
	while (s && *s)
	{
		
	}
}

char		**ft_split(char *s)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * count_words(s));
	return (tab);
}
