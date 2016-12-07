/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_metachar.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:22 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:21:23 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"

bool	ft_glob_compile_metachar(t_glob_logic *logic, char c)
{
	t_glob_token *token;

	if (GLOB_STAR == c)
		token = ft_glob_new_token(GLOB_STAR);
	else if (GLOB_QUESTION == c)
		token = ft_glob_new_token(GLOB_QUESTION);
	else if (GLOB_RBRACKET == c)
		return (false);
	else
		token = ft_glob_new_token(GLOB_CHAR);
	ft_glob_token_append(token, c);
	ft_list_add_tail(&token->list, &logic->token_head);
	return (true);
}
