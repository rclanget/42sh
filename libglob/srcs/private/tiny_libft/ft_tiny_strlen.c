/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 17:49:56 by igomez            #+#    #+#             */
/*   Updated: 2016/12/03 15:51:21 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

size_t		ft_tiny_strlen(char const *s)
{
	char const *p;

	p = s;
	while (!ALIGNED(s, sizeof(uint64_t)))
	{
		if (!*s)
			return (s - p);
		++s;
	}
	while (!DETECTNULL(*(uint64_t *)s))
		s += sizeof(uint64_t);
	while (*s)
		++s;
	return (s - p);
}
