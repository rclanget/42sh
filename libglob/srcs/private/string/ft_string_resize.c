/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:25:32 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"
#include "glob_libft.h"

bool	ft_string_resize(t_string *dst, size_t size)
{
	size_t	new_capacity;
	char	*save;

	if (size < dst->len)
	{
		dst->len = size;
		*(dst->str + dst->len) = 0;
	}
	else if (size >= dst->capacity)
	{
		size += 1;
		new_capacity = dst->capacity;
		while (new_capacity < size)
			new_capacity <<= 1;
		save = dst->str;
		if (0 == (dst->str = (char *)malloc(new_capacity)))
			return (false);
		ft_tiny_strcpy(dst->str, save);
		dst->capacity = new_capacity;
		free(save);
	}
	return (true);
}
