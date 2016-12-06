/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_join_dirs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:17:27 by Zoellingam       ###   ########.fr       */
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
