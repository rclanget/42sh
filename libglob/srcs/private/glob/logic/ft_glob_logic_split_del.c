/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_split_del.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:18:07 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"

void	ft_glob_logic_split_del(t_glob_split **tmp)
{
	ft_string_del(&(*tmp)->pre);
	ft_string_del(&(*tmp)->in);
	ft_string_del(&(*tmp)->post);
	free(*tmp);
	*tmp = 0;
}
