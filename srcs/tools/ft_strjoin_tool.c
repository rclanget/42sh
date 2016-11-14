/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:37:33 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 15:13:26 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_custom(char const *s1, char const *s2)
{
	char *str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (ft_strdup((!s1) ? s2 : s1));
	str = ft_memalloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	ft_strclr(str);
	str = ft_strcat(ft_strcat(str, s1), s2);
	return (str);
}
