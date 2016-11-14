/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 14:02:27 by rclanget          #+#    #+#             */
/*   Updated: 2016/11/14 15:15:55 by ulefebvr         ###   ########.fr       */
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
		dst = (char *)malloc((l_s3 * sizeof(char) + 1));
		i = 0;
		while (l_s3-- >= 0)
		{
			if (i < ft_strlen(s1))
				dst[i] = s1[i];
			else
			{
				dst[i] = c;
				break ;
			}
			i++;
		}
		dst[++i] = '\0';
		return (dst);
	}
	dst = (char *)malloc(sizeof(char) + 1);
	dst[0] = c;
	dst[1] = 0;
	return (NULL);
}
