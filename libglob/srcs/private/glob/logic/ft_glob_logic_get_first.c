/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_get_first.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:17:52 by Zoellingam       ###   ########.fr       */
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
