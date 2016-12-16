/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:08:38 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/15 21:45:42 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

char	*ft_str_replace(const char *str, const char *sub, const char *rpl,\
int i)
{
	char	*newstr;
	int		len_str;
	int		len_sub;
	int		len_rpl;

	newstr = 0;
	len_str = ft_strlen(str);
	len_sub = ft_strlen(sub);
	len_rpl = ft_strlen(rpl);
	if (!str || !sub)
		return (ft_strdup(str));
	newstr = ft_memalloc(len_str - len_sub + len_rpl + 1);
	if (newstr)
	{
		ft_memcpy(newstr, str, i);
		ft_memcpy(newstr + i, rpl, len_rpl);
		ft_memcpy(
			newstr + i + len_rpl,
			(char *)str + i + len_sub,
			len_str - len_sub - i);
	}
	return (newstr);
}
