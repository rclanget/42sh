/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:33:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2014/11/07 16:33:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;
	int		counter;

	start = 0;
	counter = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (ft_blank(s[start]))
		start++;
	while (ft_blank(s[end]) && end > start)
		end--;
	str = (char*)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	while (start <= end)
		str[counter++] = s[start++];
	str[counter] = '\0';
	return (str);
}
