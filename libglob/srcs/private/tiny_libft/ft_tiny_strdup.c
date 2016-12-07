/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:28:41 by rclanget         ###   ########.fr       */
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
