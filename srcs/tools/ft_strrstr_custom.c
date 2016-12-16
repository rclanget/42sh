/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:01:53 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/13 18:11:33 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

static int	is_splitable(char *str, int i)
{
	char	*operators;

	operators = "\'\"`()";
	if (!i || str[i - 1] != '\\')
	{
		if (ft_strchr(operators, str[i]))
			return (str[i] == '(' ? ')' : str[i]);
	}
	return (0);
}

static int	*check_quotes(char *str)
{
	int		quote;
	int		*tab;
	char	op;
	int		i;

	tab = (int *)ft_memalloc(sizeof(int) * ft_strlen(str));
	quote = 0;
	i = 0;
	while (str[i])
	{
		if ((op = is_splitable(str, i)) && (!quote || quote == str[i]))
		{
			tab[i] = 1;
			quote = quote ? 0 : op;
		}
		else
			tab[i] = quote ? 1 : 0;
		++i;
	}
	return (tab);
}

char		*ft_strrstr_custom(const char *meule_de_foin, const char *aiguille)
{
	int		a;
	int		len_aiguille;
	int		*quotes;

	a = ft_strlen(meule_de_foin) - 1;
	len_aiguille = ft_strlen(aiguille);
	quotes = check_quotes((char *)meule_de_foin);
	if (!aiguille || *aiguille == 0)
		return ((char*)meule_de_foin);
	while (a >= 0)
	{
		if (!quotes[a] &&
			!ft_strncmp(meule_de_foin + a, aiguille, len_aiguille))
		{
			free(quotes);
			return ((char*)meule_de_foin + a);
		}
		a--;
	}
	free(quotes);
	return (NULL);
}
