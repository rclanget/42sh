/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_ignore.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:08 by rclanget         ###   ########.fr       */
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
