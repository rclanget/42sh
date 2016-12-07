/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:16:13 by igomez            #+#    #+#             */
/*   Updated: 2016/12/03 15:50:37 by Zoellingam       ###   ########.fr       */
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
