/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:16:49 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_finder.h"

void		ft_glob_finder_del(t_list *it)
{
	ft_string_del(&C_FINDER(it)->handle);
	ft_list_del(&C_FINDER(it)->list);
	free(C_FINDER(it));
}
