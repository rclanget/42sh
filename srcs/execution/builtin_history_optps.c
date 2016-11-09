#include "history.h"
#include "builtin_history.h"
#include "libft.h"
#include "tools.h"
#include "shell.h"

char * history_perform(t_info *info, char *str)
{
    t_history *hist;
    int     offset;

    if (!(hist = get_head(info->hist)))
        return (NULL);
    offset = ft_atoi(str + 1);
    while (hist)
    {
        if (hist->n == offset)
            return (ft_strdup(hist->cmd));
        hist = hist->next;
    }
    return (NULL);
}

char    *history_add_args(char **cmd)
{
    char *tmp;
    char *tmp1;

    tmp = NULL;
    while (cmd && *cmd)
    {
        tmp1 = ft_strjoin_custom(tmp, *cmd);
        ft_free_them_all(1, &tmp);
        tmp = tmp1;
        cmd++;
    }
    return tmp;
}

int history_substitute(t_info *info, char **av, int option)
{
    char *tmp;

    if (av && *av)
    {
        if (option & OPT_P)
        {
            tmp = history_perform(info, *av);
            ft_print("%s\n", tmp ? tmp : *av);
            ft_free_them_all(1, &tmp);
        }
        else
        {
            tmp = history_add_args(av);
            free(info->hist->cmd);
            info->hist->cmd = tmp;
        }
    }
    return (0);
}
