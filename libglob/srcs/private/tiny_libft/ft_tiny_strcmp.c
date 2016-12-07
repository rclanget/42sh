/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:34 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

int		ft_tiny_strcmp(const char *s1, const char *s2)
{
	while (*(uint64_t *)s1 == *(uint64_t *)s2)
	{
		if (DETECTNULL(*(uint64_t *)s1))
			return (0);
		s1 += sizeof(uint64_t);
		s2 += sizeof(uint64_t);
	}
	while (*s1 && *(uint8_t *)s1 == *(uint8_t *)s2)
	{
		++s1;
		++s2;
	}
	return (*(uint8_t *)s1 - *(uint8_t *)s2);
}
