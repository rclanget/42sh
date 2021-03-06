/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 15:41:41 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/31 13:45:19 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "error.h"
#include "env.h"
#include "libft.h"
#include "tools.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

char *g_err_msg[] = {\
	NULL,
	"unable to found path variable",\
	"no such file or directory",\
	"permission denied",\
	"string not in pwd",\
	"not a directory",
	"too many.*symbolic links"};

#define ERR_MSG g_err_msg

char		*get_cleaned_dest(t_info *info, char *dest, int flagl)
{
	char		*tmp;
	t_env		*var;

	tmp = NULL;
	if (!ft_strcmp(dest, "-"))
	{
		if ((var = search_env_var(info, "OLDPWD")))
			tmp = ft_strdup(var->content);
	}
	else if (!ft_strncmp(dest, "~", 1))
	{
		if ((var = search_env_var(info, "HOME")))
			tmp = ft_strjoin(var->content, &dest[1]);
	}
	else
		tmp = getfullpath(search_env_var(info, "PWD") ?
			(search_env_var(info, "PWD")->content) : 0, dest, flagl);
	return (tmp);
}

int			ft_recup_error(char *tmp, int ret)
{
	struct stat		sb;

	if (stat(tmp, &sb) != -1)
	{
		if (!S_ISDIR(sb.st_mode))
			return (5);
	}
	if (errno == ELOOP)
		return (6);
	if (errno == ENOENT)
		return (2);
	if (errno == EACCES)
		return (3);
	return (ret);
}

int			cd_go_to(t_info *info, char *path, int flag)
{
	int		ret;
	char	*tmp;
	char	*current;

	ret = 0;
	tmp = NULL;
	if (!path)
		return (0);
	if (path[ft_strlen(path) - 1] == '.' && path[ft_strlen(path) - 2] == '/')
		path[ft_strlen(path) - 1] = '\0';
	current = search_env_var(info, "PWD") ?
		ft_strdup(search_env_var(info, "PWD")->content) : 0;
	if (!(++ret) || !(tmp = get_cleaned_dest(info, path, flag)) || !(++ret)
		|| access(tmp, F_OK) == -1 || !(++ret) || chdir(tmp) == -1)
	{
		if (!tmp)
			tmp = ft_strdup(path);
		ret = ft_recup_error(tmp, ret);
		ft_free_them_all(2, &tmp, &current);
		return (ret);
	}
	env_update_var(info, "OLDPWD", current);
	env_update_var(info, "PWD", tmp);
	ft_free_them_all(2, &tmp, &current);
	return (0);
}

char		*get_new_from_old(t_info *info, char **cmd)
{
	char	*tmp;
	char	*tmp2;
	int		len;
	t_env	*var;

	tmp = NULL;
	if ((var = search_env_var(info, "PWD")) &&
		(tmp = ft_strstr(var->content, cmd[1])))
	{
		tmp2 = ft_strndup(var->content, tmp - var->content);
		len = tmp - var->content + ft_strlen(cmd[1]);
		tmp = ft_strjoin(tmp2, cmd[2]);
		free(tmp2);
		tmp2 = ft_strjoin(tmp, &var->content[len]);
		free(tmp);
		tmp = tmp2;
	}
	return (tmp);
}

int			builtin_cd(t_info *info, t_tree *cmd)
{
	int		len;
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = NULL;
	if ((len = ft_tablen(cmd->cmd)) == 1)
	{
		if (!(ret = (search_env_var(info, "HOME")) ? 0 : 1))
			ret = cd_go_to(info, search_env_var(info, "HOME")->content, 0);
	}
	else if (len == 2)
		ret = cd_go_to(info, cmd->cmd[1], 0);
	else if (len == 3 && !ft_strcmp(cmd->cmd[1], "-P"))
		ret = cd_go_to(info, cmd->cmd[2], 1);
	else if (len == 3)
	{
		tmp = get_new_from_old(info, cmd->cmd);
		ret = cd_go_to(info, tmp, 0);
		ret = ret > 0 ? 4 : 0;
		free(tmp);
	}
	if (ret)
		ft_fdprint(2, "cd: %s\n", ERR_MSG[ret]);
	return (ret > 0 ? 1 : 0);
}
