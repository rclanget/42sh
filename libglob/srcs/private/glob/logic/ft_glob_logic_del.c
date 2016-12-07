/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/06 06:17:49 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"
#include "glob_logic.h"
#include "glob_token.h"

void	ft_glob_logic_del(t_list *it)
{
	t_glob_logic *logic;

	logic = C_LOGIC(it);
	ft_string_del(&logic->pattern);
	ft_list_apply(&logic->token_head, &ft_glob_token_del);
	ft_list_del(&logic->list);
	free(logic);
	logic = 0;
}
