/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_get_here.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:01 by rclanget         ###   ########.fr       */
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
