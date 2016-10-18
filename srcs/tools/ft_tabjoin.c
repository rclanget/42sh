/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 12:33:23 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 09:58:15 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#include <unistd.h>
#include <stdlib.h>

char		**ft_tabjoin(char **tab1, char **tab2)
{
	int		i;
	int		j;
	char	**tab;

	tab = NULL;
	if (tab1 && tab2)
	{
		i = ft_tablen(tab1) + ft_tablen(tab2);
		tab = (char **)malloc(sizeof(char *) * i + 1);
		i = -1;
		while (tab1[++i])
			tab[i] = tab1[i];
		j = i;
		i = -1;
		while (tab2[++i])
			tab[j + i] = tab2[i];
		tab[j + i] = 0;
	}
	return (tab);
}
