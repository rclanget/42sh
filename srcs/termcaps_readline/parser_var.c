/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:40:27 by zipo              #+#    #+#             */
/*   Updated: 2016/12/02 02:54:48 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "var.h"
#include "libft.h"
#include "shell.h"
#include "env.h"

#define IS_VALID_CHAR(x) (ft_isalpha(x) || ft_isdigit(x) || x == '_')

char		*set_content(char *cmd, char *content, int position, int len)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(cmd, 0, position);
	tmp2 = ft_strjoin(tmp, content);
	free(tmp);
	tmp = ft_strjoin(tmp2, &cmd[position + len]);
	free(tmp2);
	return (tmp);
}

char		*get_var(char *cmd, int position)
{
	int		position_save;
	char	*var;

	position_save = position++;
	while (cmd[position] && IS_VALID_CHAR(cmd[position]))
		position++;
	var = ft_strsub(cmd, position_save + 1, position - (position_save + 1));
	return (var);
}

char		*replace_var(t_info *info, char *cmd, int position)
{
	t_env	*env;
	t_alias	*var;
	char	*var_name;
	char	*content;
	char	*tmp;

	var_name = get_var(cmd, position);
	env = search_env_var(info, var_name);
	var = search_var(info, var_name);
	if (env || var)
		content = env ? env->content : var->replace;
	else
		content = "";
	if ((tmp = set_content(cmd, content, position, ft_strlen(var_name) + 1)))
	{
		free(cmd);
		cmd = tmp;
	}
	free(var_name);
	return (cmd);
}

int			isquote(char c)
{
	static	int backslash = 0;
	static	int quote = 0;
	static	int dquote = 0;
	static	int mquote = 0;

	if (c == '\'' && !backslash && !dquote && !mquote)
		quote = !quote;
	else if (c == '\"' && !backslash && !quote && !mquote)
		dquote = !dquote;
	else if (c == '`' && !backslash && !dquote && !quote)
		mquote = !mquote;
	else if (c == '\\' && !quote)
		backslash = !backslash;
	return (quote);
}

char		*parse_var(t_info *info, char *cmd)
{
	char	*tmp;
	int		i;

	tmp = cmd;
	i = 0;
	while (tmp && tmp[i])
	{
		if (!isquote(tmp[i]) && tmp[i] == '$')
			tmp = replace_var(info, tmp, i);
		i += tmp[i] ? 1 : 0;
	}
	return (tmp);
}
