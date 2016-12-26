/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_error_msg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:26:23 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/26 15:29:37 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>

char			*ft_execution_error_msg(char *cmd)
{
	struct stat sb;
	mode_t		tmp_mode;

	if ((access(cmd, X_OK)) != 0 && (access(cmd, F_OK)) == 0)
		return (ft_strdup("permission denied"));
	if (lstat(cmd, &sb) != -1)
	{
		tmp_mode = sb.st_mode;
		if (S_ISLNK(tmp_mode) && stat(cmd, &sb) == -1)
			return (ft_strdup("too many.*symbolic links"));
	}
	return (ft_strdup("command not found"));
}
