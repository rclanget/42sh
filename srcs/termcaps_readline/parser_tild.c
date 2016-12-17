/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguin <gdeguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:05:22 by gdeguin           #+#    #+#             */
/*   Updated: 2016/12/17 13:54:08 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "execution.h"
#include "tools.h"
#include "env.h"

#define SEARCH_ENV(x) (search_env_var(info, (x)))
#define GET_VAR_CONTENT(x) (SEARCH_ENV((x)) ? SEARCH_ENV((x))->content : 0)

int				find_tild(char *cmd)
{
	int		i;
	char	quote;
	char	dquote;

	i = 0;
	quote = 0;
	dquote = 0;
	while (cmd && cmd[i])
	{
		if (cmd[i] == '"')
			dquote = !dquote;
		else if (cmd[i] == '\'')
			quote = !quote;
		if (!quote && !dquote && cmd[i] == '~' && (!i || cmd[i - 1] == ' '))
		{
			if ((i && cmd[i - 1] == '\\')
				|| (cmd[i + 1] && !ft_strchr("/+- ", cmd[i + 1])))
				;
			else
				return (i);
		}
		i++;
	}
	return (0);
}

char			*replace_tild(t_info *info, char *cmd, int pos)
{
	char	*tmp;

	tmp = 0;
	if (!ft_strcmp(cmd + pos, "~") || !ft_strchr("-+", *(cmd + pos + 1)))
		tmp = ft_str_replace(cmd, "~", GET_VAR_CONTENT("HOME"), pos);
	else if (cmd[pos + 1] == '+')
		tmp = ft_str_replace(cmd, "~+", GET_VAR_CONTENT("PWD"), pos);
	else if (cmd[pos + 1] == '-')
		tmp = ft_str_replace(cmd, "~-", GET_VAR_CONTENT("OLDPWD"), pos);
	return (tmp);
}

char			*parser_tild(void *info, char *command)
{
	int			pos;
	char		*tmp;

	pos = 0;
	tmp = command;
	while ((pos = find_tild(command)))
	{
		command = replace_tild((t_info *)info, command, pos);
		free(tmp);
		tmp = command;
	}
	return (command);
}
