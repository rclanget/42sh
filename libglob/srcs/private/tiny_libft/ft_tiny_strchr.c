/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:32 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

char	*ft_tiny_strchr(char const *s, int c)
{
	uint8_t		d;
	uint64_t	k;
	uint64_t	i;

	if (!c)
		return ((char *)s + ft_tiny_strlen(s));
	d = c;
	while (!ALIGNED(s, sizeof(uint64_t)))
	{
		if (!*s)
			return (NULL);
		if (*(uint8_t *)s++ == c)
			return ((char *)--s);
	}
	i = 0;
	k = 0;
	while (i++ < sizeof(uint64_t))
		k = (k << sizeof(uint64_t)) | d;
	while (!DETECTNULL(*(uint64_t *)s) && !DETECTCHAR(*(uint64_t *)s, k))
		s += sizeof(uint64_t);
	while (*s != 0)
		if (*(uint8_t *)s++ == d)
			return ((char *)--s);
	return (NULL);
}
