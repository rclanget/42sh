/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:14:38 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/07 22:41:46 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *str, int len)
{
	char	*s;

	s = (char * )malloc(sizeof(char) * (len + 1));
	ft_bzero(s, sizeof(char) * (len + 1));
	ft_memcpy(s, str, len);
	return (s);
}
