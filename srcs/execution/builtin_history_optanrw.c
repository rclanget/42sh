#include "shell.h"
#include "history.h"
#include "builtin_history.h"
#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h>

static int history_append_to_file(t_info *info, char **av)
{
    int   ret;
    int   fd;
    t_history   *hist;

    ret = 0;

    hist = get_head(info->hist);
    if (hist && ((fd = open((av && *av) ? *av : HIST_FILE, FLAG_APPEND, OPEN_MODE)) != -1))
    {
        ret = 1;
        while (hist->next)
            hist = hist->next;
        while (hist)
        {
            ft_putendl_fd(hist->cmd, fd);
            hist = hist->prev;
        }
        close(fd);
    }
    return (ret);
}

static int history_append_to_list(t_info *info, char **av)
{
    int  fd;
    char    *line;

    line = NULL;
    if ((fd = open((av && *av) ? *av : HIST_FILE, FLAG_READ, OPEN_MODE)) == -1)
        return (0);
    while (get_next_line(fd, &line))
    {
        add_history(&(*info), line);
        free(line);
    }
    close(fd);
    return (1);
}

static int history_file_to_list(t_info *info, char **av)
{
    int  fd;
    char    *line;

    line = NULL;
    free_history(info->hist);
    info->hist = NULL;
    if ((fd = open((av && *av) ? *av : HIST_FILE, FLAG_READ, OPEN_MODE)) == -1)
        return (0);
    while (get_next_line(fd, &line))
    {
        add_history(&(*info), line);
        free(line);
    }
    close(fd);
    return (1);
}

static int history_list_to_file(t_info *info, char **av)
{
    int   ret;
    int   fd;
    t_history   *hist;

    ret = 0;
    hist = get_head(info->hist);
    if (hist && ((fd = open((av && *av) ? *av : HIST_FILE, FLAG_TRUNC, OPEN_MODE)) != -1))
    {
        ret = 1;
        while (hist->next)
            hist = hist->next;
        while (hist)
        {
            ft_putendl_fd(hist->cmd, fd);
            hist = hist->prev;
        }
        close(fd);
    }
    return (ret);
}

int history_file(t_info *info, char **av, int option)
{
    int ret;

    ret = 0;
    if (option & OPT_A)
        ret = history_append_to_file(info, av);
    else if (option & OPT_N)
        ret = history_append_to_list(info, av);
    else if (option & OPT_R)
        ret = history_file_to_list(&(*info), av);
    else if (option & OPT_W)
        ret = history_list_to_file(info, av);
    return (ret);
}