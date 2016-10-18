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

void hashmap_free(t_hashmap *map)
{
  if (map)
  {
    hashmap_free(map->next);
    free(map->key);
    free(map->value);
    free(map);
  }
}
