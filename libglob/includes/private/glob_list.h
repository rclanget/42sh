/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2016/12/06 17:46:33 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_LIST_H
# define GLOB_LIST_H

/*
** ============================================================================
** Linus Torval linked list
**	==> https://github.com/torvalds/linux/blob/master/include/linux/list.h
*/
typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*
** Init first item of list properly
*/
# define INIT_LIST_HEAD(x)			(x) = (t_list){&(x), &(x)}

/*
** Get offset of 'ptr' in struct 'st' simulating it with ptr 0
*/
# define OFFSETOF(st, m) 			((unsigned int)(&(((st *)0)->m)))
# define CONTAINEROF(ptr, st, m)	((st *)((char *)(ptr) - OFFSETOF(st, m)))

/*
** Add item to the head of list
*/
void				ft_list_add(
						t_list *new,
						t_list *head
);

/*
**	Add item to the end of list
*/
void				ft_list_add_tail(
						t_list *new,
						t_list *head
);

/*
** Apply 'func' to every item in list
*/
void				ft_list_apply(
						t_list *head,
						void (*func)(t_list *)
);

/*
** Unlink item from list.
*/
void				ft_list_del(
						t_list *item
);

#endif
