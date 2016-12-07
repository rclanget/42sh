/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:20:43 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:20:45 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_compile.h"

char	*ft_glob_handler(char const *line, void (*err_func)(char const *))
{
	return (ft_glob_finder_engine(line, err_func));
}
