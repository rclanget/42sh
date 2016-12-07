/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_token_from_char.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:26 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_token.h"

bool	ft_glob_new_token_from_char(t_glob_logic *logic, char c)
{
	t_glob_token *new;

	if (0 != (new = ft_glob_new_token(GLOB_CHAR)))
	{
		ft_glob_token_append(new, c);
		ft_list_add_tail(&new->list, &logic->token_head);
		return (true);
	}
	return (false);
}
