/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 17:31:04 by igomez            #+#    #+#             */
/*   Updated: 2016/12/04 00:56:55 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

void	ft_tiny_bzero(void *m, size_t n)
{
	void *p;

	p = m;
	while (!ALIGNED(p, sizeof(uint64_t)) && n)
	{
		*(uint8_t *)p++ = 0;
		--n;
	}
	while (n >= sizeof(uint64_t))
	{
		*(uint64_t *)p = 0;
		p += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	while (n--)
		*(uint8_t *)p++ = 0;
}
