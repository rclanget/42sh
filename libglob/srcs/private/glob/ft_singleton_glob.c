/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton_glob.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 17:36:28 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

t_glob		*ft_singleton_glob(void)
{
	static t_glob *p = 0;

	if (0 == p)
	{
		if (0 != (p = (t_glob *)malloc(sizeof(t_glob))))
		{
			ft_tiny_bzero(p, sizeof(t_glob));
			INIT_LIST_HEAD(p->logic_head);
			INIT_LIST_HEAD(p->finder_head);
		}
	}
	return (p);
}
