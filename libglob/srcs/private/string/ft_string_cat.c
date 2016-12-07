/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:25:20 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"
#include "glob_libft.h"

bool	ft_string_cat(t_string *dst, const char *src)
{
	size_t	len;

	if (0 != src)
	{
		len = ft_tiny_strlen(src);
		if (0 != dst && true == ft_string_resize(dst, dst->len + len))
		{
			ft_tiny_strcpy(dst->str + dst->len, src);
			dst->len += len;
			return (true);
		}
	}
	return (false);
}
