/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_pattern.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:16:37 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

bool	ft_glob_compile_pattern(t_glob_logic *logic)
{
	char const	*p;
	int			ret;
	char		c;

	ret = 1;
	p = logic->pattern->str;
	while (0 != (c = *p++))
	{
		if (GLOB_ESCAPE == c && GLOB_EOS != *p)
			ft_glob_new_token_from_char(logic, *p++);
		else if (GLOB_LBRACKET != c)
		{
			if (0 == (ret = ft_glob_compile_metachar(logic, c)))
				break ;
		}
		else if (GLOB_RBRACKET != *p)
		{
			if (0 == (ret = ft_glob_compile_list(logic, p, *p == GLOB_NOT)))
				break ;
			p += ret;
		}
		else
			++p;
	}
	return (!!ret);
}
