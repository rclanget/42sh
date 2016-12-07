/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 18:06:01 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_token.h"
#include "glob_libft.h"

#define GLOB_IS_QUOTE(c)	('\'' == (c) || '`' == (c) || '"' == (c))

static size_t	ft_glob_finder_split_quote(char const *line, char quote)
{
	char const	*line_save;

	line_save = line++;
	while (GLOB_EOS != *line && quote != *line)
	{
		if (GLOB_ESCAPE == *line)
			if (GLOB_EOS == *++line)
				break ;
		++line;
	}
	if (line != line_save)
		++line;
	return ((size_t)(line - line_save));
}

static bool		ft_glob_finder_split_handle_quote(char const *line,
					size_t *i, bool *escaped)
{
	*escaped = false;
	if (GLOB_ESCAPE == *(line + *i))
	{
		*i = *i + 1;
		*escaped = true;
		if (GLOB_EOS == *(line + *i))
			return (false);
	}
	if (false == *escaped && GLOB_IS_QUOTE(*(line + *i)))
		*i = *i + ft_glob_finder_split_quote(line + *i, *(line + *i));
	else
		while (GLOB_EOS != *(line + *i) && !ft_tiny_isspace(*(line + *i)))
			*i = *i + 1;
	return (true);
}

static size_t	ft_glob_finder_split_count(char const *line)
{
	bool	escaped;
	size_t	i;
	size_t	j;
	size_t	w;

	i = 0;
	w = 0;
	while (GLOB_EOS != *(line + i))
	{
		while (true == ft_tiny_isspace(*(line + i)))
			++i;
		j = i;
		if (false == ft_glob_finder_split_handle_quote(line, &i, &escaped))
			break ;
		if (i != j)
			++w;
	}
	if (0 != w)
		++w;
	return (w);
}

char			**ft_glob_finder_split(char const *line)
{
	bool	escaped;
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	w;

	tab = (char **)malloc(sizeof(char *) * ft_glob_finder_split_count(line));
	if (0 == tab)
		return (0);
	i = 0;
	w = 0;
	while (GLOB_EOS != *(line + i))
	{
		while (true == ft_tiny_isspace(*(line + i)))
			++i;
		j = i;
		if (false == ft_glob_finder_split_handle_quote(line, &i, &escaped))
			break ;
		if (i != j)
			tab[w++] = ft_tiny_strndup(line + j, i - j);
	}
	tab[w] = 0;
	return (tab);
}
