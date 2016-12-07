/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:18 by rclanget         ###   ########.fr       */
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
