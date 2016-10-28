/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:40:47 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 12:59:49 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_STRUCT_H
# define HASHMAP_STRUCT_H

typedef struct			s_hashmap
{
	char				**map;
	unsigned int		size;
}						t_hashmap;

#endif
