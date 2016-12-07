/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_string.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:19:40 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:19:41 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_STRING_H
# define GLOB_STRING_H

/*
** Include size_t, malloc, free
*/
# include <stdlib.h>

/*
** Include bool, true, false
*/
# include <stdbool.h>

/*
** ============================================================================
** String struct. It does handle allocation by itself
*/
typedef struct		s_string
{
	char			*str;
	size_t			len;
	size_t			capacity;
}					t_string;

/*
** Create new string with size
*/
t_string			*ft_string_new(
						size_t size
);

/*
** Create new string using strdup
*/
t_string			*ft_string_dup(
						char const *s
);

/*
** Append char to string
*/
bool				ft_string_add(
						t_string *dst,
						char c
);

/*
** Cat str to string
*/
bool				ft_string_cat(
						t_string *dst,
						char const *s
);

/*
** Erase and free string
*/
bool				ft_string_del(
						t_string **ptr
);

/*
** Resize string if needef
*/
bool				ft_string_resize(
						t_string *dst,
						size_t new_size
);

#endif
