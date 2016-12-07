/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 18:40:27 by igomez            #+#    #+#             */
/*   Updated: 2016/12/04 02:58:30 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_libft.h"

char	*ft_tiny_strdup(char const *s)
{
	char	*new;
	size_t	len;

	len = ft_tiny_strlen(s) + 1;
	if ((new = (char *)malloc(len)) == 0)
		return (0);
	ft_tiny_bzero(new, len);
	ft_tiny_strcpy(new, s);
	return (new);
}
