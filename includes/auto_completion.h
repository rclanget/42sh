#ifndef MY_AUTO_COMPLETION
# define MY_AUTO_COMPLETION

#include "libft.h"

typedef struct              s_dlist
{
    char                    *str;
    char                    pos;
    struct s_dlist          *suiv;
}                           t_dlist;

typedef struct  s_auto_comp
{
    char	*current_dir;
    char    *line;
    int     flag;
    t_dlist	*list_words;
}               t_auto_comp;

#endif
