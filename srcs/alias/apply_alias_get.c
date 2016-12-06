/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_alias_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 15:46:39 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/06 15:46:44 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "alias_struct.h"

char		*get_other(char *cmd, int *code)
{
	int		start;

	start = 0;
	while (cmd[start] && code[start] != C_CMD)
		++start;
	return (ft_strsub(cmd, 0, start));
}

char		*get_command(char *cmd, int *code)
{
	int		start;

	start = 0;
	while (cmd[start] && code[start] == C_CMD)
		++start;
	return (ft_strsub(cmd, 0, start));
}

t_word		*get_the_list(char *s, int *c)
{
	t_word	*word;
	int		len;

	len = 0;
	word = 0;
	if (s && *s && (word = ft_memalloc(sizeof(t_word))))
	{
		word->word = (*c == C_CMD) ? get_command(s, c) : get_other(s, c);
		word->treat = (*c == C_CMD) ? 1 : 0;
		len += ft_strlen(word->word);
		word->next = get_the_list(s + len, c + len);
	}
	return (word);
}
