/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_split_del.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:48 by rclanget         ###   ########.fr       */
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
