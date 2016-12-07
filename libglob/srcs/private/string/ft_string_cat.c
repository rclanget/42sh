/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/04 01:05:10 by Zoellingam       ###   ########.fr       */
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
