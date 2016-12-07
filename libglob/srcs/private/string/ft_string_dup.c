/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:25:27 by rclanget         ###   ########.fr       */
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
