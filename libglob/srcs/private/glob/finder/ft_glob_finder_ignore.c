/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_ignore.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 17:27:52 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"
#include "glob_token.h"

bool		ft_glob_finder_ignore(char const *pattern)
{
	while ('-' == *pattern)
		++pattern;
	if ('"' == *pattern && '"' == *(pattern + ft_tiny_strlen(pattern) - 1))
		return (true);
	if ('`' == *pattern && '`' == *(pattern + ft_tiny_strlen(pattern) - 1))
		return (true);
	if ('\'' == *pattern && '\'' == *(pattern + ft_tiny_strlen(pattern) - 1))
		return (true);
	while (GLOB_EOS != *pattern)
		if (0 != ft_tiny_strchr(GLOB_TOKENS, *pattern++))
			return (false);
	return (true);
}
