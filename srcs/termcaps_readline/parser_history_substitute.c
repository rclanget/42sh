/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_history_substitute.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:18:07 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/12 15:26:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "builtin_history.h"

int			ft_digitlen(char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		++i;
	return (i);
}

void		replace_at(char **cmd, int from, int to, char *by)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strdup(&(*cmd[from + to]));
	tmp2 = ft_strndup(*cmd, from);
	tmp3 = ft_strjoin(tmp2, by);
	ft_free_them_all(1, &tmp2);
	tmp2 = ft_strjoin(tmp3, tmp);
	ft_free_them_all(3, &tmp, &tmp3, cmd);
	*cmd = tmp2;
}

int			get_subsitution(t_info *info, char **cmd, int i)
{
	char	*str;
	char	*repl;
	int		len;

	str = *cmd + i + 1;
	if (ft_isdigit(*str))
	{
		len = ft_digitlen(str);
		if (!(repl = history_perform(info, *cmd + i)))
		{
			ft_free_them_all(1, cmd);
			*cmd = ft_strdup("42sh: Event not found");
			return (-1);
		}
		replace_at(cmd, i, len, repl);
		return (0);
	}
	return (-1);
}

char		*history_excldot(t_info *info, char *cmd)
{
	int		i;
	int		quote;

	i = 0;
	quote = 0;
	while (i != -1 && cmd && cmd[i])
	{
		if (cmd[i] == '\'' && ++i)
			quote = !quote;
		else if (!quote && cmd[i] == '!')
			i = get_subsitution(info, &cmd, i);
		else
			i++;
	}
	if (cmd && i == -1)
	{
		ft_print("42sh: %s :Event not found\n", cmd);
		ft_free_them_all(1, &cmd);
		cmd = ft_strdup("");
	}
	return (cmd);
}
