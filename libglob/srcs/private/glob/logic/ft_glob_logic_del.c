/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:38 by rclanget         ###   ########.fr       */
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
