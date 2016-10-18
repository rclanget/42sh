/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:55:47 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 13:02:00 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

int			ft_putcharb(int c);
char		*ft_strjoinb(char *s1, char *s2, int n);
char		*ft_strndup(char *str, int n);
int			ft_tablen(char **tab);
char		**ft_tabjoin(char **tab1, char **tab2);
char		*ft_strjoinc(char const *s1, char const c);
char		*ft_strjoin_custom(char const *s1, char const *s2);

#endif
