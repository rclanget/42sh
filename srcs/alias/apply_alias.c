/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_alias.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:59:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/11/14 12:30:54 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "alias_struct.h"
#include "alias.h"

static void		free_list(t_word *list)
{
	if (list)
	{
		free_list(list->next);
		free(list->word);
		free(list);
	}
}

t_alias			*search_alias2(t_info *info, char *var, int *position)
{
	t_alias *alias;

	*position = 0;
	alias = info->alias;
	while (alias && var)
	{
		if (!ft_strcmp(alias->init, var))
			break ;
		alias = alias->next;
		(*position)++;
	}
	*position = alias ? *position : -1;
	return (alias);
}

char			*make_sentence(t_word *words)
{
	char *tmp;
	char *sentence;

	if (words->next)
	{
		tmp = make_sentence(words->next);
		sentence = ft_strjoin(words->word, tmp);
		free(tmp);
	}
	else
		sentence = ft_strdup(words->word);
	return (sentence);
}

char			*apply_alias(t_info *info, t_word *ws, char *cmd, char *visited)
{
	int			i;
	char		*replace;
	char		*tmp;
	t_alias		*alias;
	t_word		*w;

	w = ws;
	tmp = ft_strdup(visited);
	while (w && tmp)
	{
		if (w->treat && (alias = search_alias2(info, w->word, &i)) && !tmp[i]++)
		{
			free(w->word);
			w->word = apply_alias(info, get_the_list(alias->replace,
				definition_code(alias->replace)),
				ft_strdup(alias->replace), ft_strdup(tmp));
		}
		ft_strcpy(tmp, visited);
		w = w->next;
	}
	replace = make_sentence(ws);
	free_list(ws);
	ft_free_them_all(3, &cmd, &visited, &tmp);
	return (replace);
}

char			*apply_alias_verified(t_info *info, char *command)
{
	char		*tmp;

	if (*command)
	{
		tmp = apply_alias(
			info,
			get_the_list(command, definition_code(command)),
			ft_strdup(command),
			ft_memalloc(sizeof(char) * len_alias(info->alias)));
		free(command);
		command = tmp;
	}
	return (command);
}
