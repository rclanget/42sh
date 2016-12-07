/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:29 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

t_glob_token	*ft_glob_new_token(int type)
{
	t_glob_token	*new;

	if (0 != (new = (t_glob_token *)malloc(sizeof(t_glob_token))))
	{
		ft_tiny_bzero(new, sizeof(t_glob_token));
		new->type = type;
		new->handle = ft_string_new(1);
	}
	return (new);
}
