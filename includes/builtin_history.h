#ifndef BUILTIN_HISTORY_H
# define BUILTIN_HISTORY_H

#define			HIST_FILE "./.42sh_hist"
#define			FLAG_APPEND O_WRONLY | O_APPEND | O_CREAT
#define			FLAG_TRUNC O_RDWR | O_TRUNC | O_CREAT
#define			FLAG_READ O_RDONLY
#define			OPEN_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

#define 		OPT_C 0x001
#define 		OPT_D 0x002
#define 		OPT_A 0x004
#define 		OPT_N 0x008
#define 		OPT_R 0x010
#define 		OPT_W 0x020
#define 		OPT_P 0x040
#define 		OPT_S 0x080

char			*history_perform(t_info *info, char *str);
char			*history_add_args(char **cmd);
int				history_substitute(t_info *info, char **av, int option);

int				history_base(t_info *info, char **av);
int				history_clear(t_info *info, char **av);
int				history_deloffset(t_info *info, char **av);

int				history_file(t_info *info, char **av, int option);

char			*history_excldot(t_info *info, char *cmd);

#endif
