/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:23:15 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 16:34:53 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa2(int n)
{
	static char		number[25];
	int				i;

	i = 0;
	ft_bzero(number, sizeof(char) * 25);
	if (n < 0)
		number[0] = '-';
	n *= (n < 0) ? -1 : 1;
	i = ft_nbrlen(n);
	if (n == 0)
		number[0] = '0';
	while (n)
	{
		number[--i] = '0' + (n % 10);
		n = n / 10;
	}
	return (number);
}
