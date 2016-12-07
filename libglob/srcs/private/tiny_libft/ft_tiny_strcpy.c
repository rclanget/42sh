/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/04 01:00:24 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

char	*ft_tiny_strcpy(char *s1, char const *s2)
{
	char *s;

	s = s1;
	while (!DETECTNULL(*(uint64_t *)s2))
	{
		*(uint64_t *)s = *(uint64_t *)s2;
		s += sizeof(uint64_t);
		s2 += sizeof(uint64_t);
	}
	while ((*s++ = *s2++) != 0)
		continue;
	return (s1);
}
