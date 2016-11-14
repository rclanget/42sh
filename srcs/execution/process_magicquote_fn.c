/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_magicquote_fn.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:11:10 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 14:47:02 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "alias_struct.h"
#include "execution.h"
#include "operator.h"

static char		*get_words(char *s)
{
	char		*tmp;
	int			quote;
	char		c;

	tmp = s;
	quote = 0;
	while (tmp && *tmp)
	{
		if (!quote && *tmp == '\\' && *(tmp + 1))
			++tmp;
		else if ((*tmp == '\'' || *tmp == '\"'))
		{
			if ((!quote && (c = *tmp)) || (quote && c == *tmp))
				quote = !quote;
		}
		else if (*tmp == '`' && !quote)
			break ;
		++tmp;
	}
	return (ft_strsub(s, 0, tmp - s));
}

static char		*get_next_word(char *s, int *treat)
{
	char		*tmp;
	char		*ret;

	ret = NULL;
	tmp = s;
	if (*tmp)
	{
		if (*tmp != '`')
			ret = get_words(tmp);
		else
		{
			ret = get_words(s + 1);
			*treat = 1;
		}
	}
	return (ret);
}

t_word			*get_magicquotelist(char *s)
{
	t_word		*word;
	int			treat;

	treat = 0;
	word = NULL;
	if (s && *s && (word = ft_memalloc(sizeof(t_word))))
	{
		word->word = get_next_word(s, &treat);
		word->treat = treat;
		word->next = get_magicquotelist(s + ft_strlen(word->word) +
			(treat ? 2 : 0));
	}
	return (word);
}

t_word			*treat_magicquote(t_info *info, t_word *words)
{
	t_word		*tmp;
	char		*treated;

	tmp = words;
	while (tmp)
	{
		if (tmp->treat)
		{
			treated = process_magicquote(info, tmp->word);
			save_fd(0);
			free(tmp->word);
			tmp->word = treated;
		}
		tmp = tmp->next;
	}
	return (words);
}
