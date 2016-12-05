/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:18:49 by zipo              #+#    #+#             */
/*   Updated: 2016/12/05 13:16:42 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "shell.h"
#include "get_next_line.h"
#include "var.h"
#include "env.h"

#define OPT_R	0x001

char		*regroup_content(char **content, int position)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strdup(content[position]);
	while (content[position] && content[position + 1])
	{
		tmp2 = ft_strjoinc(tmp, ' ');
		free(tmp);
		tmp3 = ft_strjoin(tmp2, content[++position]);
		free(tmp2);
		tmp = tmp3;
	}
	return (tmp);
}

int			r_update_var(t_info *info, char **var, char *line)
{
	int		i;
	char	**content;
	char	*tmp;

	i = 0;
	content = ft_strsplit(line, ' ');
	free(line);
	while (var[i] && content[i])
	{
		tmp = (!var[i + 1] && content[i + 1]) ? \
		regroup_content(content, i) : content[i];
		update_var(info, var[i], tmp);
		if (!var[i + 1] && content[i + 1])
			free(tmp);
		i++;
	}
	free_tab(content);
	return (0);
}

char		*check_optr(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (line[i])
		if (line[i++] == '\\')
			j++;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(line) + j + 1);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\\')
			tmp[j++] = line[i];
		tmp[j] = line[i];
		i++;
		j++;
	}
	tmp[j] = 0;
	free(line);
	return (tmp);
}

char		*check_backslash_at_end(char *line)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	if (line[ft_strlen(line) - 1] == '\\')
	{
		ft_putstr(">");
		get_next_line(0, &tmp);
		tmp2 = ft_strsub(line, 0, (ft_strlen(line) - 1));
		free(line);
		line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		if (tmp)
			free(tmp);
		if (line[ft_strlen(line) - 1] == '\\')
			return (check_backslash_at_end(line));
	}
	return (line);
}

int			builtin_read(t_info *info, t_tree *cmd)
{
	char	**var;
	char	*line;
	int		opt;
	int		i;

	line = NULL;
	var = cmd->cmd + 1;
	if ((i = ft_option(0, cmd->cmd, "r", &opt)) < 0)
		return (1);
	get_next_line(0, &line);
	if (line)
	{
		if (opt & OPT_R)
		{
			var = cmd->cmd + 2;
			line = check_optr(line);
		}
		else
			line = check_backslash_at_end(line);
		return (r_update_var(info, var, line));
	}
	return (1);
}
