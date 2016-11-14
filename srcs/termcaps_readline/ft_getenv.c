/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:12:41 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 17:27:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"

#include <unistd.h>

char		*ft_getenv(char **env, char *var)
{
	int		len;

	len = ft_strlen(var);
	while (env && *env)
	{
		if ((!ft_strncmp(var, *env, len)) && ((*env)[len] == '='))
			return (ft_strdup(&(*env)[len + 1]));
		env++;
	}
	return (NULL);
}
