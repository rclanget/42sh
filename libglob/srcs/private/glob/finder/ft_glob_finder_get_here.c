/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_get_here.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:17:12 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_string.h"
#include <stdlib.h>

char		*ft_glob_finder_get_here(char const *pattern)
{
	t_string	*new;
	char		*res;

	res = 0;
	if (0 != pattern && 0 != (new = ft_string_new(1)))
	{
		if ('/' == *pattern)
			++pattern;
		while ('/' != *pattern)
			ft_string_add(new, *pattern++);
		res = new->str;
		free(new);
	}
	return (res);
}
