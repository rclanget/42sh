// gcc srcs/termcaps_readline/parser_clean_backslash.c test/test_parser_clean_backslash.c -Iincludes -Ilibft/includes libft/libft.a
#include <stdio.h>
#include "parser.h"
#include "libft.h"

int main(void)
{
    int check = 0;

    char *str = ft_strdup("\\test bonjour");
    char *result = "test bonjour";
    char *tmp = NULL;

    tmp = clean_backslash(str);
    check += ft_strcmp(tmp, result);
    // printf("[%s] : [%s]", str, tmp);
    // printf(" [%c]\n", check ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\test \\bonjour");
    tmp = clean_backslash(str);
    check += ft_strcmp(tmp, result);

    // printf("[%s] : [%s]", str, tmp);
    // printf(" [%c]\n", check ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\");
    result = &""[0];
    tmp = clean_backslash(str);
    check += ft_strcmp(tmp, result);
    
    // printf("[%s] : [%s]", str, tmp);
    // printf(" [%c]\n", check ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\\\");
    result = &""[0];
    tmp = clean_backslash(str);
    check += ft_strcmp(tmp, result);

    // printf("[%s] : [%s]", str, tmp);
    // printf(" [%c]\n", check ? 'X' : 'V');
    free(tmp);

    str = ft_strdup("\\test\\ \\bonjour\\");
    result = &"test bonjour"[0];
    tmp = clean_backslash(str);
    check += ft_strcmp(tmp, result);

    // printf("[%s] : [%s]", str, tmp);
    // printf(" [%c]\n", check ? 'X' : 'V');
    free(tmp);

    exit (check ? 1 : 0);
} 