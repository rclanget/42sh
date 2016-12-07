/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:11 by rclanget         ###   ########.fr       */
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
