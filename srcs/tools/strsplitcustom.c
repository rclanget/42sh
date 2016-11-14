/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplitcustom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:17:18 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 15:20:29 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tools.h"

static char			*remove_quote(char *str)
{
	char			c;
	char			*tmp;
	char			*tmp2;

	c = 0;
	tmp = str;
	tmp2 = str;
	while (tmp && *tmp)
	{
		if (*tmp == '\\' && *(tmp + 1))
		{
			*tmp2++ = *tmp++;
			*tmp2++ = *tmp++;
		}
		else if ((*tmp == '\'' || *tmp == '\"') && (!c || c == *tmp))
		{
			c = (!c) ? *tmp : 0;
			tmp++;
		}
		else
			*tmp2++ = *tmp++;
	}
	*tmp2 = *tmp;
	return (str);
}

static char			*seek_next_delimiter(char *str)
{
	char			quote;
	int				chr;

	quote = 0;
	chr = 0;
	while (str && *str && *str == ' ' && ++str)
	{
		;
	}
	while (str && *str)
	{
		if (!chr && *str == '\\' && (chr = 1))
			continue;
		else if (!chr && (*str == '\'' || *str == '\"'))
			quote = (quote && *str == quote) ? 0 : *str;
		else if (chr && !quote && *str && *(str + 1) == ' ')
			str++;
		else if (!chr && !quote && *str == ' ')
			break ;
		if (chr)
			chr = 0;
		++str;
	}
	return (str);
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
		ret = clean_backslash(remove_quote(ft_strtrim(tmp)));
		free(tmp);
		del = (!*del) ? NULL : del;
		if (ret && !*ret)
			ft_memdel((void **)&ret);
		content = del;
	}
	return (ret);
}

char				**cust_split(char *str)
{
	int				nword;
	char			*tmp;
	char			**tab;
	char			*tmptab[ft_strlen(str) / 2 + 1];

	nword = 0;
	tab = NULL;
	get_next_word(str);
	while ((tmp = get_next_word(NULL)))
		tmptab[nword++] = tmp;
	if (nword)
	{
		tab = (char **)ft_memalloc(sizeof(char *) * (nword + 1));
		tab[nword] = 0;
		while (nword--)
			tab[nword] = tmptab[nword];
	}
	return (tab);
}
