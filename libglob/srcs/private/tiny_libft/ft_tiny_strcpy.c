/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:38 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

char	*ft_tiny_strcpy(char *s1, char const *s2)
{
	char *s;

	s = s1;
	while (!DETECTNULL(*(uint64_t *)s2))
	{
		*(uint64_t *)s = *(uint64_t *)s2;
		s += sizeof(uint64_t);
		s2 += sizeof(uint64_t);
	}
	while ((*s++ = *s2++) != 0)
		continue;
	return (s1);
}
