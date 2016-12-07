/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/03 15:46:36 by Zoellingam       ###   ########.fr       */
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