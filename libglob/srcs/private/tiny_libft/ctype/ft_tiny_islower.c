/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_islower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 23:13:58 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/03 16:51:48 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

int	ft_tiny_islower(int c)
{
	return (ft_ctype_mask(c, M_LOWER));
}
