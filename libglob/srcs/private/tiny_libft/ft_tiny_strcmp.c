/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 18:28:03 by igomez            #+#    #+#             */
/*   Updated: 2016/12/04 00:58:35 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

int		ft_tiny_strcmp(const char *s1, const char *s2)
{
	while (*(uint64_t *)s1 == *(uint64_t *)s2)
	{
		if (DETECTNULL(*(uint64_t *)s1))
			return (0);
		s1 += sizeof(uint64_t);
		s2 += sizeof(uint64_t);
	}
	while (*s1 && *(uint8_t *)s1 == *(uint8_t *)s2)
	{
		++s1;
		++s2;
	}
	return (*(uint8_t *)s1 - *(uint8_t *)s2);
}
