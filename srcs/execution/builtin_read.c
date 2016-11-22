/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:18:49 by zipo              #+#    #+#             */
/*   Updated: 2016/11/23 00:17:26 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "shell.h"
#include "get_next_line.h"
#include "var.h"

char        *regroup_content(char **content, int position)
{
    char    *tmp;
    char    *tmp2;
    char    *tmp3;

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

int         builtin_read(t_info * info, t_tree *cmd)
{
    char    **var;
    char    **content;
    char    *line;
    char    *tmp;
    int     i;

    (void)info;
    var = cmd->cmd + 1;
    i = 0;
    get_next_line(0, &line);
    content = ft_strsplit(line, ' ');
    free(line);
    while (var[i] && content[i])
    {
        tmp = (!var[i + 1] && content[i + 1]) ? regroup_content(content, i) : content[i];
        update_var(info, var[i], tmp);
        if (!var[i + 1] && content[i + 1])
            free(tmp);
        i++;
    }
    return (1);
}
