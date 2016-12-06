/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 17:36:05 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_match.h"

bool	ft_glob_match(char const *string, char const *glob_pattern)
{
	bool	ret;
	t_list	*it;

	ret = false;
	if (0 != string && 0 != glob_pattern)
	{
		if (true == ft_glob_compile(glob_pattern))
		{
			it = ft_singleton_glob()->logic_head.next;
			while (it != &ft_singleton_glob()->logic_head)
			{
				if (true == (ret = ft_glob_match_here(
					C_LOGIC(it)->token_head.next,
					&C_LOGIC(it)->token_head, string)))
					break ;
				it = it->next;
			}
		}
	}
	ft_delete_glob();
	return (ret);
}
