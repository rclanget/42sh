#include "shell.h"
#include "history.h"
#include "builtin_history.h"
#include "libft.h"
#include "tools.h"

int check_options(int option)
{
    int ret;
    int act;

    ret = 1;
    act = 0;
    if ((option & OPT_C) && ++act)
        ret = 2;
    if ((option & OPT_D) && ++act)
        ret = 3;
    if (((option & OPT_A) || (option & OPT_N) || (option & OPT_R) || (option & OPT_W)) && ++act)
        ret = 4;
    if (((option & OPT_P) || (option & OPT_S)) && ++act)
        ret = 5;
    return ((act > 1) ? 0 : ret);
}

int builtin_history(t_info *info, t_tree *cmd)
{
    int  option;
    int  i;
    char    **av;

    option = 0;
    if ((i = ft_option(ft_tablen(cmd->cmd), cmd->cmd, "cdanrwps", &option)) == -1)
		return 0;
    av = cmd->cmd + i;
    i = 0;
    if ((i = check_options(option)))
    {
        if (i == 1) // history [n]
            history_base(info, av);
        else if (i == 2) // history -c
            history_clear(info, av);
        else if (i == 3) // history -d offset
            history_deloffset(info, av);
        else if (i == 4) // history -anrw
            history_file(&(*info), av, option);
        else if (i == 5) // history -ps
            history_substitute(info, av, option);
    }
    else
        ft_putendl_fd("history: bad options\nhistory: usage: history [-c] [-d offset] [n] or history -anrw [filename] or history -ps arg [arg...]", 2);
    return (0);
}
