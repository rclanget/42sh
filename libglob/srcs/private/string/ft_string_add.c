/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/03 15:48:27 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"

bool	ft_string_add(t_string *dst, char c)
{
	if (0 == dst || false == ft_string_resize(dst, dst->len + 1))
		return (false);
	*(dst->str + dst->len++) = c;
	*(dst->str + dst->len) = 0;
	return (true);
}
