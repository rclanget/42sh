/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:18:49 by zipo              #+#    #+#             */
/*   Updated: 2016/11/30 14:47:05 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "shell.h"
#include "get_next_line.h"
#include "var.h"
#include "env.h"

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

int			builtin_read(t_info *info, t_tree *cmd)
{
	char	**var;
	char	*line;
	int		i;

	line = NULL;
	var = cmd->cmd + 1;
	if ((i = ft_option(0, cmd->cmd, "r", &i)) < 0)
		return (1);
	i = 0;
	get_next_line(0, &line);
	if (line)
		return (r_update_var(info, var, line));
	return (1);
}
