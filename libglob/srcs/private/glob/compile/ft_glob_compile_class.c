/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_class.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:20:54 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:20:55 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

static const t_glob_ascii g_ascii[] =
{
	{9, "[:alnum:]", &ft_tiny_isalnum},
	{9, "[:alpha:]", &ft_tiny_isalpha},
	{9, "[:blank:]", &ft_tiny_isblank},
	{9, "[:cntrl:]", &ft_tiny_iscntrl},
	{9, "[:digit:]", &ft_tiny_isdigit},
	{9, "[:graph:]", &ft_tiny_isgraph},
	{9, "[:lower:]", &ft_tiny_islower},
	{9, "[:punct:]", &ft_tiny_ispunct},
	{9, "[:space:]", &ft_tiny_isspace},
	{9, "[:upper:]", &ft_tiny_isupper},
	{10, "[:xdigit:]", &ft_tiny_isxdigit},
	{0, 0, 0}
};

int		ft_glob_compile_class(t_glob_token *token, char const *p)
{
	size_t	i;
	char	c;

	i = 0;
	while (0 != g_ascii[i].pattern)
	{
		if (0 == ft_tiny_strncmp(g_ascii[i].pattern, p, g_ascii[i].size))
		{
			c = 0;
			while ((uint8_t)c < 0xff)
			{
				if (false != g_ascii[i].func(c))
					ft_glob_token_append(token, c);
				++c;
			}
			return (g_ascii[i].size);
		}
		++i;
	}
	return (0);
}
