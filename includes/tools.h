/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:55:47 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 16:29:54 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

char			*ft_strjoinb(char *s1, char *s2, int n);
char			*ft_strndup(char *str, int n);
int				ft_tablen(char **tab);
char			**ft_tabjoin(char **tab1, char **tab2);
char			*ft_strjoinc(char const *s1, char const c);
char			*ft_strjoin_custom(char const *s1, char const *s2);
char			*clean_backslash(char *str, char quote);
char			**cust_split(char *str);
int				ft_signal(int i);
int				ft_isalnum_or_dot(int c);
char			*ft_strdup_spe(const char *s1);
char			*ft_itoa2(int n);
unsigned int	diff_address(const char *s1, const char *s2);
int				ft_str_isalnum_spe(char *s);
void			*free_tab(char **tab);

#endif
