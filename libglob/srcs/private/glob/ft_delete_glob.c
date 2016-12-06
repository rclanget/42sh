/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_glob.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/06 06:18:47 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

void	ft_delete_glob(void)
{
	t_glob *p;

	p = ft_singleton_glob();
	if (0 != p)
	{
		ft_list_apply(&p->logic_head, &ft_glob_logic_del);
		INIT_LIST_HEAD(p->logic_head);
	}
}
