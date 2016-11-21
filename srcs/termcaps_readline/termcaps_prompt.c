/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:06:17 by zipo              #+#    #+#             */
/*   Updated: 2016/11/21 18:31:12 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

char *get_prompt(t_info *info)
{
    t_env   *e;

    e = search_env_var(info, "PS1");
    if (ft_strcmp(info->term->prompt, (e && e->content) ? e->content : "?> "))
    {
        free(info->term->prompt);
        info->term->prompt = ft_strdup((e && e->content) ? e->content : "?> ");
    }
    return (info->term->prompt);
}
