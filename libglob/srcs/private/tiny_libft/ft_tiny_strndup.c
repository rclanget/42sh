/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strndup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:51 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

char		*ft_tiny_strndup(char const *s, size_t n)
{
	char		*new;
	char const	*p;
	size_t		len;

	p = s;
	while (n >= sizeof(uint64_t) && 0 != DETECTNULL(*(uint64_t *)p))
	{
		p += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	while (0 != n-- && 0 != *p)
		++p;
	len = p - s;
	if (0 != (new = (char *)malloc(len + 1)))
	{
		(void)ft_tiny_memcpy(new, s, len);
		*(new + len) = 0;
	}
	return (new);
}
