/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/03 15:50:53 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

void		*ft_tiny_memcpy(void *dst, void const *src, size_t n)
{
	void	*p1;
	void	*p2;

	if (src != dst)
	{
		p1 = dst;
		p2 = (void *)src;
		while (n >= sizeof(uint64_t))
		{
			*(uint64_t *)p1 = *(uint64_t *)p2;
			p1 += sizeof(uint64_t);
			p2 += sizeof(uint64_t);
			n -= sizeof(uint64_t);
		}
		while (0 < n--)
			*(uint8_t *)p1++ = *(uint8_t *)p2++;
	}
	return (dst);
}
