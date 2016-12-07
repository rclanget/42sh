/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_logic_get_second.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 06:18:00 by Zoellingam       ###   ########.fr       */
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
