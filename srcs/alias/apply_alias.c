/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_alias.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 14:59:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 11:03:03 by rclanget         ###   ########.fr       */
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
	char		*tmp;
	t_alias		*alias;
	t_word		*w;
	int			*codes;

	w = ws;
	tmp = ft_strdup(visited);
	while (w && tmp)
	{
		if (w->treat && (alias = search_alias2(info, w->word, &i)) && !tmp[i]++)
		{
			free(w->word);
			codes = definition_code(alias->replace);
			w->word = apply_alias(info, get_the_list(alias->replace, codes),
						ft_strdup(alias->replace), ft_strdup(tmp));
			free(codes);
		}
		ft_strcpy(tmp, visited);
		w = w->next;
	}
	ft_free_them_all(3, &cmd, &visited, &tmp);
	tmp = make_sentence(ws);
	free_list(ws);
	return (tmp);
}

char			*apply_alias_verified(t_info *info, char *command)
{
	char		*tmp;
	int			*def_code;

	if (*command)
	{
		def_code = definition_code(command);
		tmp = apply_alias(info, get_the_list(command, def_code),
				ft_strdup(command),
				ft_memalloc(sizeof(char) * (len_alias(info->alias) + 1)));
		free(def_code);
		free(command);
		command = tmp;
	}
	return (command);
}
