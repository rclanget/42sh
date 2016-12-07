/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_get_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:05 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"

char		*ft_glob_finder_get_next(char const *pattern)
{
	char	*res;

	res = 0;
	if (0 != pattern)
	{
		if ('/' == *pattern)
			++pattern;
		while (GLOB_EOS != *pattern && '/' != *pattern)
			++pattern;
		if ('/' == *pattern)
			++pattern;
		if (GLOB_EOS != *pattern)
			res = (char *)pattern;
	}
	return (res);
}
