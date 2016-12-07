/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/03 23:37:13 by Zoellingam       ###   ########.fr       */
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
