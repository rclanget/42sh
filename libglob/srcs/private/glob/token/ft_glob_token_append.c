/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_token_append.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:32 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_token.h"
#include "glob_string.h"
#include "glob_libft.h"

void	ft_glob_token_append(t_glob_token *token, char c)
{
	if (0 == ft_tiny_strchr(token->handle->str, c))
		ft_string_add(token->handle, c);
}
