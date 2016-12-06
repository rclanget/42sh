/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/04 01:05:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"
#include "glob_libft.h"

t_string			*ft_string_new(size_t size)
{
	t_string	*res;
	size_t		capacity;

	size += 1;
	capacity = 16;
	while (capacity < size)
		capacity <<= 1;
	if (0 == (res = (t_string *)malloc(sizeof(t_string))))
		return (0);
	if (0 == (res->str = (char *)malloc(sizeof(char) * capacity)))
	{
		free(res);
		res = 0;
	}
	else
	{
		ft_tiny_bzero((void *)res->str, sizeof(char) * capacity);
		res->len = 0;
		res->capacity = capacity;
	}
	return (res);
}
