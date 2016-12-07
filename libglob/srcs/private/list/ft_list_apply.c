/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:25:12 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_list.h"

void	ft_list_apply(t_list *head, void (*func)(t_list *))
{
	t_list	*it;
	t_list	*next;

	if (0 != head)
	{
		it = head->next;
		while (it != head)
		{
			next = it->next;
			func(it);
			it = next;
		}
	}
}
