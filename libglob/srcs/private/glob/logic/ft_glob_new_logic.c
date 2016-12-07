/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:55 by rclanget         ###   ########.fr       */
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
