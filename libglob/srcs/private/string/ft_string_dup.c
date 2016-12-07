/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2016/12/06 17:32:54 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"
#include "glob_libft.h"

t_string			*ft_string_dup(char const *s)
{
	t_string	*p;
	size_t		len;

	len = ft_tiny_strlen(s);
	if (0 != (p = ft_string_new(len)))
	{
		ft_tiny_strcpy(p->str, s);
		p->len = len;
	}
	return (p);
}
