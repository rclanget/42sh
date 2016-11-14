/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 14:02:27 by rclanget          #+#    #+#             */
/*   Updated: 2016/11/14 17:14:00 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

char	*ft_strjoinc(char const *s1, char const c)
{
	char			*dst;
	int				l_s3;
	unsigned int	i;

	dst = NULL;
	if (s1 != NULL && c)
	{
		l_s3 = ft_strlen(s1) + 1;
		dst = (char *)ft_memalloc((l_s3 * sizeof(char) + 1));
		i = 0;
		ft_strcat(dst, s1);
		dst[ft_strlen(s1)] = c;
		return (dst);
	}
	dst = (char *)malloc(sizeof(char) + 1);
	dst[0] = c;
	dst[1] = 0;
	return (NULL);
}
