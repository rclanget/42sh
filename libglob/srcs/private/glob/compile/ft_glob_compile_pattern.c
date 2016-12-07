/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_pattern.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:31 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:21:32 by rclanget         ###   ########.fr       */
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
