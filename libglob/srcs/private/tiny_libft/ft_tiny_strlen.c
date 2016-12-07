/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:44 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

size_t		ft_tiny_strlen(char const *s)
{
	char const *p;

	p = s;
	while (!ALIGNED(s, sizeof(uint64_t)))
	{
		if (!*s)
			return (s - p);
		++s;
	}
	while (!DETECTNULL(*(uint64_t *)s))
		s += sizeof(uint64_t);
	while (*s)
		++s;
	return (s - p);
}
