/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_token_from_char.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/06 06:18:37 by Zoellingam       ###   ########.fr       */
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
