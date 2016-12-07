/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:52 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

t_glob_split	*ft_glob_logic_split(char const *p)
{
	t_glob_split	*split;
	char			*lcurly;
	char			*rcurly;

	split = 0;
	if (0 != (lcurly = ft_glob_logic_get_first(p)))
	{
		if (0 != (rcurly = ft_glob_logic_get_second(lcurly)))
		{
			split = (t_glob_split *)malloc(sizeof(t_glob_split));
			if (0 != split)
			{
				split->in = ft_string_new(1);
				split->pre = ft_string_new(1);
				split->post = ft_string_new(1);
				while (p != lcurly)
					ft_string_add(split->pre, *p++);
				while (++lcurly != rcurly)
					ft_string_add(split->in, *lcurly);
				while (GLOB_EOS != *++rcurly)
					ft_string_add(split->post, *rcurly);
			}
		}
	}
	return (split);
}
