/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 22:20:12 by igomez            #+#    #+#             */
/*   Updated: 2016/12/03 15:50:45 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

int		ft_tiny_memcmp(void const *s1, void const *s2, size_t n)
{
	void *p1;
	void *p2;

	if (s1 != s2)
	{
		p1 = (void *)s1;
		p2 = (void *)s2;
		while (n >= sizeof(uint64_t))
		{
			if (*(uint64_t *)p1 != *(uint64_t *)p2)
				break ;
			p1 += sizeof(uint64_t);
			p2 += sizeof(uint64_t);
			n -= sizeof(uint64_t);
		}
		while (n--)
			if (*(uint8_t *)p1++ != *(uint8_t *)p2++)
				return (*(uint8_t *)--p1 - *(uint8_t *)--p2);
	}
	return (0);
}
