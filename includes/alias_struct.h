/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:56:43 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 13:02:16 by ulefebvr         ###   ########.fr       */
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

#endif
