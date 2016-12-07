/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:18:15 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:18:17 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOB_H
# define FT_GLOB_H

/*
** Glob handler
*/
char	*ft_glob_handler(char const *line, void (*err_func)(char const *p));

#endif
