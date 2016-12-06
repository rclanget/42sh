/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_range.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:16:41 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"

int		ft_glob_compile_range(t_glob_token *token, char const *p)
{
	char	c;

	if (GLOB_EOS != *(p + 2) && GLOB_LBRACKET != *(p + 2))
	{
		if ((unsigned char)*p < (unsigned char)*(p + 2))
		{
			c = (int)*p;
			while (c <= (int)*(p + 2))
				ft_glob_token_append(token, c++);
			return (3);
		}
	}
	return (0);
}
