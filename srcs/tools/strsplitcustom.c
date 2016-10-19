/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplitcustom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:17:18 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/19 16:17:41 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char *beg;
	char *end;
	char *ret;

	ret = NULL;
	if (s)
	{
		beg = (char *)s;
		end = (char *)&(s[ft_strlen(s) - 1]);
		while ((*beg == ' ' || *beg == '\n' || *beg == '\t') && ++beg);
		while ((*beg == ' ' || *beg == '\n' || *beg == '\t') && --end);
		if (++end - beg >= 0 && (ret = ft_memalloc(sizeof(char) * (end - beg + 1))))
			ret = ft_memcpy(ret, beg, (end - beg));
	}
	return ret;
}


static char			*seek_next_delimiter(char *str)
{
	char			quote;
	int				chr;

	quote = 0;
	chr = 0;
	while (str && *str && *str == ' ' && ++str);
	while (str && *str)
	{
		if (!chr && *str == '\\' && (chr = 1))
			continue;
		else if (!chr && (*str == '\'' || *str == '\"'))
			quote = (quote && *str == quote) ? 0 : *str;
		else if (!chr && !quote && *str == ' ')
			break;
		if (chr)
			chr = 0;
		++str;
	}
	return str;
}

static char			*get_next_word(char *str)
{
	static char		*content;
	char			*del;
	char			*ret;
	char			*tmp;

	ret = NULL;
	content = (str) ? str : content;
	if (!str && content)
	{
		del = seek_next_delimiter(content);
		tmp = ft_memalloc(sizeof(char) * (del - content + 1));
		tmp = ft_memcpy(tmp, content, (del - content));
		ret = ft_strtrim(tmp);
		free(tmp);
		if (!*del)
			del = NULL;
		content = del;
	}
	return ret;
}

char				**cust_split(char *str)
{
	int				nword;
	char			*tmp;
	char			**tab;
	char			*tmptab[ft_strlen(str)];

	nword = 0;
	get_next_word(str);
	while ((tmp = get_next_word(NULL)))
		tmptab[nword++] = tmp;
	tab = (char **)ft_memalloc(sizeof(char *) * (nword + 1));
	tab[nword] = 0;
	while (nword--)
		tab[nword] = tmptab[nword];
	return (tab);
}
