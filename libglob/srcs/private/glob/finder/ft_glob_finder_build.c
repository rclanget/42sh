/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_build.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:16:46 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_match.h"
#include "glob_token.h"
#include "glob_libft.h"

char		*ft_glob_finder_build(void)
{
	t_string	*r;
	char		*ret;
	t_list		*it;

	ret = 0;
	it = ft_singleton_glob()->finder_head.next;
	if (it != &ft_singleton_glob()->finder_head)
	{
		if (0 != (r = ft_string_new(1)))
		{
			while (it != &ft_singleton_glob()->finder_head)
			{
				ft_string_cat(r, C_FINDER(it)->handle->str);
				if (it->next != &ft_singleton_glob()->finder_head)
					ft_string_add(r, ' ');
				it = it->next;
			}
			ret = r->str;
			free(r);
		}
	}
	return (ret);
}