/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_get_second.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:45 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"
#include "glob_libft.h"

char		*ft_glob_logic_get_second(char const *lcurly)
{
	while (GLOB_EOS != *lcurly)
	{
		if (GLOB_ESCAPE == *lcurly && GLOB_EOS == *++lcurly)
			break ;
		if (GLOB_RCURLY == *lcurly)
			return ((char *)lcurly);
		++lcurly;
	}
	return (0);
}
