/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clean_backslash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:55:39 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/19 11:55:59 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

char *clean_backslash(char *str)
{
    int     i;
    int     j;
    char     *str_new;

    i = 0;
    j = 0;
    while (str[j++])
        if (str[j] != '\\')
            i++;
    str_new = ft_memalloc(i);
    j = 0;
    i = 0;
    while (str[j])
    {
        if (str[j] != '\\')
            str_new[i++] = str[j++];
        else
            j++;
    }
    free(str);
    return (str_new);
}

