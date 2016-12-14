/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 14:39:06 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/14 14:26:23 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			*free_tab(char **tab)
{
	int			i;

	i = -1;
	if (!tab)
		return (NULL);
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}
