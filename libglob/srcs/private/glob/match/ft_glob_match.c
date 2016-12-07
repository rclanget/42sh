/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:23 by rclanget         ###   ########.fr       */
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
