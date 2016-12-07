/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 12:58:42 by igomez            #+#    #+#             */
/*   Updated: 2016/12/03 15:46:45 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_list.h"

void		ft_list_del(t_list *entry)
{
	entry->next->prev = entry->prev;
	entry->prev->next = entry->next;
}
