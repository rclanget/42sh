/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_logic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:16:30 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"
#include <stdlib.h>

static int		ft_glob_logic_is_separator(int c)
{
	return (GLOB_SEPARATOR == c);
}

void			ft_glob_compile_logic(char const *p)
{
	t_glob_split	*sep;
	t_string		*tmp;
	char			**tab;
	size_t			i;

	if (0 == (sep = ft_glob_logic_split(p)))
		return (ft_glob_new_logic(p));
	i = 0;
	tab = ft_tiny_split_func(sep->in->str, &ft_glob_logic_is_separator);
	if (0 != tab)
	{
		while (0 != *(tab + i))
		{
			tmp = ft_string_dup(sep->pre->str);
			ft_string_cat(tmp, *(tab + i));
			ft_string_cat(tmp, sep->post->str);
			ft_glob_compile_logic(tmp->str);
			ft_string_del(&tmp);
			free(*(tab + i++));
		}
		free(tab);
	}
	ft_glob_logic_split_del(&sep);
}
