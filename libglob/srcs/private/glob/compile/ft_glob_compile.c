/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:16:19 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"
#include "glob_token.h"

bool	ft_glob_compile(char const *pattern)
{
	t_list			*it;

	ft_glob_compile_logic(pattern);
	it = ft_singleton_glob()->logic_head.next;
	while (it != &ft_singleton_glob()->logic_head)
	{
		if (false == ft_glob_compile_pattern(C_LOGIC(it)))
			return (false);
		it = it->next;
	}
	return (true);
}
