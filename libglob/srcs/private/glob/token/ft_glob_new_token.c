/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_new_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/06 06:18:34 by Zoellingam       ###   ########.fr       */
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
