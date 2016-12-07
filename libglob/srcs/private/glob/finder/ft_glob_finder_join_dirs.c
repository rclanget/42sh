/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_join_dirs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:14 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_finder.h"
#include "glob_token.h"
#include <stdlib.h>

char		*ft_glob_finder_join_dirs(char const *dir, char const *p)
{
	t_string	*new;
	char		*ret;

	ret = 0;
	if (0 != (new = ft_string_dup(dir)))
	{
		ft_string_add(new, '/');
		ft_string_cat(new, p);
		ret = new->str;
		free(new);
	}
	return (ret);
}
