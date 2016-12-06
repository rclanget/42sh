/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_isxdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 23:14:28 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/03 16:52:25 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

int	ft_tiny_isxdigit(int c)
{
	return (ft_ctype_mask(c, M_XDIGIT));
}
