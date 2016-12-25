/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:59:02 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/25 20:46:17 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include "hashmap_struct.h"
# include <stdlib.h>

void			*free_tab(char **tab);
unsigned int	jenkins_one_at_a_time_hash(char *key, size_t len);
int				check_access(char *str);
char			*lire_hashmap(t_hashmap *hashmap, char *key);
char			*change_path(void);

# define HASHMAP_SIZE 600000

#endif
