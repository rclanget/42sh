/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strndup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/06 06:16:03 by Zoellingam       ###   ########.fr       */
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
