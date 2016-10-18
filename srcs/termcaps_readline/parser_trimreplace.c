/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_trimreplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:30:38 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 09:19:10 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int		ft_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrimb(char *s)
{
	char	*ret;
	char	*tmp;

	ret = s;
	tmp = &(s[ft_strlen(s) - 1]);
	if (s && *s)
	{
		while (s && ft_blank(*s))
			s++;
		while (tmp >= s && ft_blank(*tmp))
			tmp--;
		if (tmp - s)
		{
			ret = ft_memalloc(tmp - s + 2);
			ft_memcpy(ret, s, tmp - s + 1);
		}
	}
	return (ret);
}
