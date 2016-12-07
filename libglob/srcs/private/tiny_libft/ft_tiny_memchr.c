/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:15 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

void	*ft_tiny_memchr(void const *m, int c, size_t n)
{
	void		*p;
	uint8_t		i;
	uint64_t	k;

	p = (void *)m;
	while (!ALIGNED(p, sizeof(uint64_t)) && n)
	{
		if (*(uint8_t *)p++ == (uint8_t)c)
			return (--p);
		--n;
	}
	i = 0;
	k = 0;
	while (i++ < sizeof(uint64_t))
		k = (k << sizeof(uint64_t)) | (uint8_t)c;
	while ((!DETECTNULL(*(uint64_t *)p ^ k)) && n > sizeof(uint64_t))
	{
		p += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	while (n--)
		if (*(uint8_t *)p++ == (uint8_t)c)
			return (--p);
	return (0);
}
