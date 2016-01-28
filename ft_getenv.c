/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:12:41 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/28 15:38:12 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

char        *ft_getenv(char *var)
{
    char    **env;
    int     len;

    len = ft_strlen(var);
    env = __environ;
    while (env && *env)
    {
        if ((!ft_strncmp(var, *env, len)) && ((*env)[len] == '='))
            return (ft_strdup(&(*env)[len + 1]));
        env++;
    }
    return (NULL);
}
