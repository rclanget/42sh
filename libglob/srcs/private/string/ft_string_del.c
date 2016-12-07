/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:25:23 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"

bool	ft_string_del(t_string **ptr)
{
	if (0 == ptr || 0 == *ptr)
		return (false);
	if (0 != (*ptr)->str)
	{
		free((*ptr)->str);
		(*ptr)->str = 0;
	}
	if (0 != *ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (true);
}
