/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_compile_metachar.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:16:33 by Zoellingam       ###   ########.fr       */
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
