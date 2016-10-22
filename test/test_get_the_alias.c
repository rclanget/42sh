// gcc srcs/alias/apply_alias_get.c srcs/alias/apply_alias.c srcs/termcaps_readline/parser_definition_code.c srcs/termcaps_readline/parser_definition_code_get.c srcs/alias/add_alias.c test/test_get_the_alias.c -Iincludes -Ilibft/includes libft/libft.a
#include <stdio.h>
#include "alias.h"
#include "libft.h"
#include "parser.h"
#include "command_line_termcaps.h"

int main(void)
{
	t_info info;
	char *visited;
	char cmd[BUFFER_SIZE] = "ls -l test ; ls";

	ft_bzero(&info, sizeof(info));
	visited = ft_memalloc(sizeof(char) * 7);
	info.alias = NULL;

	add_alias(&info, "ls", "cat");
	add_alias(&info, "cat", "echo roger ; ls");
	add_alias(&info, "echo", "cd");
	// add_alias(&info, "cd", "ls");

	printf("%s\n", apply_alias(&info, get_the_list(cmd), ft_strdup(cmd), visited));

	sleep(15);

	return (1);
}
