/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_get_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:17:16 by Zoellingam       ###   ########.fr       */
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
