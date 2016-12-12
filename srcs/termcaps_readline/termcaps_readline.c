/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:16:21 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/12 15:03:58 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "get_next_line.h"
#include "command_line_termcaps.h"

#include <unistd.h>

char		check_quote(char *cmd, char quote)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\\' && quote == '\'')
			;
		else if (cmd[i] == '\\' && cmd[i + 1])
			++i;
		else if (quote && cmd[i] == quote)
			quote = 0;
		else if (!quote && (cmd[i] == '\'' || cmd[i] == '\"'))
			quote = cmd[i];
		++i;
	}
	return (quote);
}

char		*getnextline(t_info *info, char quote)
{
	char	*cmd;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		ret;

	cmd = NULL;
	(void)info;
	ret = get_next_line(0, &cmd);
	if (cmd && (quote = check_quote(cmd, quote)))
	{
		tmp = getnextline(info, quote);
		tmp2 = ft_strjoin(cmd, "\n");
		tmp3 = ft_strjoin(tmp2, tmp);
		ft_free_them_all(3, &cmd, &tmp, &tmp2);
		cmd = tmp3;
	}
	return (ret ? cmd : NULL);
}

char		*getnextlineb(t_info *info)
{
	char	*cmd;
	int		ret;

	cmd = NULL;
	(void)info;
	ret = get_next_line(0, &cmd);
	return (ret ? cmd : NULL);
}

char		*get_currentline(t_info *info, int term, char quote)
{
	char	*cmd;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	ft_print(!quote ? "%s" : "> ", get_prompt(info));
	cmd = ((term) ? termcaps_loop(info) : getnextlineb(info));
	if (cmd && (quote = check_quote(cmd, quote)))
	{
		info->term->pos_c = 0;
		tmp = get_currentline(info, term, quote);
		tmp2 = ft_strjoin(cmd, "\n");
		tmp3 = ft_strjoin(tmp2, tmp);
		ft_free_them_all(3, &cmd, &tmp, &tmp2);
		cmd = tmp3;
	}
	return (cmd);
}

char		*termcaps_readline(t_info *info)
{
	int		term;
	char	*str;

	if (isatty(0))
	{
		termcaps_save(1);
		term = termcaps_activation(info->term->is_term);
		str = get_currentline(info, term, 0);
		termcaps_save(0);
		return (str);
	}
	else
	{
		return (getnextline(info, 0));
	}
	return (NULL);
}
