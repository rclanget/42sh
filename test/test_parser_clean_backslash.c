// gcc srcs/termcaps_readline/parser_clean_backslash.c test/test_parser_clean_backslash.c -Iincludes -Ilibft/includes libft/libft.a
#include <stdio.h>
#include "parser.h"
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("\\test bonjour");
    char *result = "test bonjour";
    char *tmp = NULL;
    printf("[%s] : [%s]", str, tmp = clean_backslash(str));
    printf(" [%c]\n", ft_strcmp(tmp, result) ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\test \\bonjour");
    printf("[%s] : [%s]", str, tmp = clean_backslash(str));
    printf(" [%c]\n", ft_strcmp(tmp, result) ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\");
    result = &""[0];
    printf("[%s] : [%s]", str, tmp = clean_backslash(str));
    printf(" [%c]\n", ft_strcmp(tmp, result) ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\\\");
    result = &""[0];
    printf("[%s] : [%s]", str, tmp = clean_backslash(str));
    printf(" [%c]\n", ft_strcmp(tmp, result) ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\test\\ \\bonjour\\");
    result = &"test bonjour"[0];
    printf("[%s] : [%s]", str, tmp = clean_backslash(str));
    printf(" [%c]\n", ft_strcmp(tmp, result) ? 'X' : 'V');
    free(tmp);

    return (1);
} 