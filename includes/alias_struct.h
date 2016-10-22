/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:56:43 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/22 14:39:12 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_STRUCT_H
# define ALIAS_STRUCT_H

typedef struct		s_alias
{
	char			*init;
	char			*replace;
	struct s_alias	*next;
}					t_alias;

typedef struct		s_word
{
	char 			*word;
	int 			treat;
	struct s_word 	*next;
}					t_word;

#endif
