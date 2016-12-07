/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:46 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:21:47 by rclanget         ###   ########.fr       */
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
