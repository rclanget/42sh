/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_token_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:35 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_string.h"
#include "glob_token.h"

void	ft_glob_token_del(t_list *it)
{
	t_glob_token *token;

	token = C_TOKEN(it);
	ft_string_del(&token->handle);
	ft_list_del(&token->list);
	free(token);
	token = 0;
}
