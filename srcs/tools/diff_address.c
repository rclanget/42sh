/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_address.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:49:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/11 16:17:00 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	diff_address(const char *s1, const char *s2)
{
	unsigned int	i;
	char			*tmp;

	tmp = (char *)s2;
	i = 0;
	while (s1 != tmp)
	{
		tmp++;
		i++;
	}
	return (i);
}
