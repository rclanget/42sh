/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton_glob.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:43 by rclanget         ###   ########.fr       */
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
