/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:34:34 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 15:00:31 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap_struct.h"

#include <stdlib.h>

void hashmap_free(t_hashmap *hashmap)
{
	unsigned int	i;
	char 			**map;

	i = 0;
	map = hashmap->map;
	while (i < 29496729)
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	free(map);
	map = NULL;
	hashmap->size = 0;
}
