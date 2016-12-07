/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_get_first.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:42 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

char		*ft_glob_logic_get_first(char const *p)
{
	size_t	count;
	size_t	save_count;
	char	*save;

	save = 0;
	count = 0;
	save_count = 0;
	while (GLOB_EOS != *p)
	{
		if (GLOB_ESCAPE == *p && GLOB_EOS == *++p)
			break ;
		else if (GLOB_LCURLY == *p)
		{
			if (save_count < ++count)
			{
				save_count = count;
				save = (char *)p;
			}
		}
		else if (GLOB_RCURLY == *p)
			--count;
		++p;
	}
	return ((0 != count) ? 0 : save);
}
