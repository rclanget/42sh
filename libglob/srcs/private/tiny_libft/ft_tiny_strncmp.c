/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 18:31:09 by igomez            #+#    #+#             */
/*   Updated: 2016/12/03 21:55:48 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

int		ft_tiny_strncmp(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (0);
	while (n >= sizeof(uint64_t) && *(uint64_t *)s1 == *(uint64_t *)s2)
	{
		n -= sizeof(uint64_t);
		if (!n || DETECTNULL(*(uint64_t *)s1))
			return (0);
		s1 += sizeof(uint64_t);
		s2 += sizeof(uint64_t);
	}
	while (n-- && *(uint8_t *)s1 == *(uint8_t *)s2)
	{
		if (!n || !*s1)
			return (0);
		++s1;
		++s2;
	}
	return (*(uint8_t *)s1 - *(uint8_t *)s2);
}
