/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:26 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

void	*ft_tiny_memset(void *p, int c, size_t n)
{
	void		*m;
	uint8_t		k;
	uint64_t	kw;

	m = (void *)p;
	k = (uint8_t)(c & 0xff);
	kw = k | (k << 8) | (k << 16) | (k << 24);
	kw = kw | (kw << 32);
	while (!ALIGNED(m, sizeof(uint8_t)) && n)
	{
		*(uint8_t *)m++ = k;
		--n;
	}
	while (n >= sizeof(uint64_t))
	{
		*(uint64_t *)m = kw;
		m += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	while (n--)
		*(uint8_t *)m++ = k;
	return (p);
}
