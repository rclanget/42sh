/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:25:17 by rclanget         ###   ########.fr       */
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
