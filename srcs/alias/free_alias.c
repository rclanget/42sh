/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 13:44:54 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:19:16 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias_struct.h"

#include <stdlib.h>

void		free_alias(t_alias *alias)
{
	if (alias)
	{
		free_alias(alias->next);
		free(alias->init);
		free(alias->replace);
		free(alias);
	}
}
