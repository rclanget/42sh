/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_agreg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:20:25 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/06 17:07:32 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "execution.h"

char		**clean_command(char **cmd, int i, int size)
{
	while (cmd && cmd[i + size])
	{
		free(cmd[i]);
		cmd[i] = cmd[i + size];
		++i;
	}
	cmd[i] = 0;
	return (cmd);
}

char		**redirection_agreg(char **cmd)
{
	int		i;
	int		size;

	i = 0;
	while (cmd && cmd[i])
	{
		if ((size = is_redirection_agreg(cmd, i)))
		{
			cmd = clean_command(cmd, i, size);
		}
		++i;
	}
	return (cmd);
}
