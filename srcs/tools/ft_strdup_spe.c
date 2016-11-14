/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:47 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/09 11:16:49 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup_spe(const char *s1)
{
	char	*str;
	int		a;

	a = 0;
	str = NULL;
	if (s1 && (str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 2))))
	{
		while (s1[a])
		{
			str[a] = s1[a];
			a++;
		}
		str[a] = '/';
		str[a + 1] = '\0';
		return (str);
	}
	else
		return (NULL);
}
