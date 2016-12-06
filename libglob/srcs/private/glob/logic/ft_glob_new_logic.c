/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:18:11 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

void	ft_glob_new_logic(char const *p)
{
	t_glob_logic	*new;
	t_list			*it;

	it = ft_singleton_glob()->logic_head.next;
	while (it != &ft_singleton_glob()->logic_head)
	{
		if (0 == ft_tiny_strcmp(C_LOGIC(it)->pattern->str, p))
			return ;
		it = it->next;
	}
	if (0 != (new = (t_glob_logic *)malloc(sizeof(t_glob_logic))))
	{
		new->pattern = ft_string_dup(p);
		INIT_LIST_HEAD(new->token_head);
		ft_list_add_tail(&new->list, &ft_singleton_glob()->logic_head);
	}
}
