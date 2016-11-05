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

char    *ft_strdup_spe(const char *s1)
{
    char    *str;
    int     a;

    a = 0;
    str = NULL;
    if (s1 && (str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 2))))
    {
        while (s1[a])
        {
            str[a] = s1[a];
            a++;
        }
        str[a] = '/';
        str[a + 1] = '\0';
        return (str);
    }
    else
        return (NULL);
}

t_dlist        *ajouter_avant(t_dlist *element, char *str, int is_dir)
{
    t_dlist     *nouvel_element;

    nouvel_element = malloc(sizeof(*nouvel_element));
    if (nouvel_element != NULL)
    {
        nouvel_element->pos = '0';
        if (is_dir)
            nouvel_element->str = ft_strdup_spe(str);
        else
            nouvel_element->str = ft_strdup(str);
        nouvel_element->suiv = element;
        //ft_print("lelement courant est %s , le suivant %s\n", nouvel_element->str, nouvel_element->suiv->str);
        return (nouvel_element);
    }
}

t_dlist         *cree_liste(char *str, int is_dir)
{
    t_dlist     *racine;

    racine = malloc(sizeof(*racine));
    if (racine != NULL)
    {
        racine->pos = '0';
        racine->suiv = NULL;
        if (is_dir)
            racine->str = ft_strdup_spe(str);
        else
            racine->str = ft_strdup(str);
    }
    return (racine);
}

void vider_liste(t_dlist *head_ref)
{
   t_dlist* current = head_ref;
   t_dlist* next;
 
   while (current != NULL) 
   {
       next = current->suiv;
       ft_strdel(&current->str);
       free(current);
       current = next;
   }
}


void print_list_completion(t_dlist *head)
{
    t_dlist *tmp;

    tmp = head;
    if (!head)
        return ;
    ft_putendl("************affichage de la liste*********");
    while (tmp && tmp->suiv != NULL)
    {
        ft_putendl((char*)tmp->str);
        ft_putchar((char)tmp->pos);
        ft_putchar('\n');
        tmp = tmp->suiv;
    }
    ft_putendl((char*)tmp->str);
    ft_putchar((char)tmp->pos);
    ft_putchar('\n');
        tmp = tmp->suiv;
    ft_putendl("************fin        affichage de la liste************");
}

#endif
