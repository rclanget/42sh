/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:03 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:21:08 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

static const char *g_class[] =
{
	"[:alnum:]",
	"[:alpha:]",
	"[:blank:]",
	"[:cntrl:]",
	"[:digit:]",
	"[:graph:]",
	"[:lower:]",
	"[:punct:]",
	"[:space:]",
	"[:upper:]",
	"[:xdigit:]",
	0
};

static bool	ft_glob_compile_is_class(char const *p)
{
	size_t i;

	i = 0;
	while (0 != g_class[i])
	{
		if (0 == ft_tiny_strncmp(p, g_class[i], ft_tiny_strlen(g_class[i])))
			return (true);
		++i;
	}
	return (false);
}

int			ft_glob_compile_list(t_glob_logic *logic, char const *p, bool n)
{
	char const		*s;
	t_glob_token	*new;

	s = p + n;
	new = ft_glob_new_token(GLOB_LIST);
	ft_list_add_tail(&new->list, &logic->token_head);
	new->is_not = n;
	while (GLOB_EOS != *s && GLOB_RBRACKET != *s)
	{
		if (GLOB_ESCAPE == *s && GLOB_EOS != *++s)
			ft_glob_token_append(new, *s++);
		else if (GLOB_LBRACKET == *s && true == ft_glob_compile_is_class(s))
			s += ft_glob_compile_class(new, s);
		else if (GLOB_RANGE == *(s + 1) && GLOB_EOS != *(s + 2)
				&& GLOB_RBRACKET != *(s + 2))
			s += ft_glob_compile_range(new, s);
		else
			ft_glob_token_append(new, *s++);
	}
	if (GLOB_RBRACKET == *s)
		return (s - p + 1);
	ft_glob_token_del(&new->list);
	return (0);
}
