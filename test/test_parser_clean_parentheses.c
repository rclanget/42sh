// gcc srcs/termcaps_readline/parser_clean_parentheses.c test/test_parser_clean_parentheses.c -Iincludes -Ilibft/includes libft/libft.a
#include <stdio.h>
#include "parser.h"

int main(void)
{
	int i = 0;
	char *str = "(TEST)";
	printf("[%s] : [%s] | i : %d\n", str, clean_parentheses(str, &i), i);
	printf("[%s] : [%s] | i : %d\n", str, "TEST", 9);
	printf("-------------------\n\n");

	i = 0;
	str = &"TEST)"[0];
	printf("[%s] : [%s] | i : %d\n", str, clean_parentheses(str, &i), i);
	printf("[%s] : [%s] | i : %d\n", str, str, 0);
	printf("-------------------\n\n");

	i = 0;
	str = &"(TEST"[0];
	printf("[%s] : [%s] | i : %d\n", str, clean_parentheses(str, &i), i);
	printf("[%s] : [%s] | i : %d\n", str, str, 0);
	printf("-------------------\n\n");

	i = 0;
	str = &"TEST"[0];
	printf("[%s] : [%s] | i : %d\n", str, clean_parentheses(str, &i), i);
	printf("[%s] : [%s] | i : %d\n", str, str, 0);
	printf("-------------------\n\n");

	i = 0;
	str = &"()"[0];
	printf("[%s] : [%s] | i : %d\n", str, clean_parentheses(str, &i), i);
	printf("[%s] : [%s] | i : %d\n", str, "", 9);
	printf("-------------------\n\n");

	i = 0;
	str = &"(TEST\\)"[0];
	printf("[%s] : [%s] | i : %d\n", str, clean_parentheses(str, &i), i);
	printf("[%s] : [%s] | i : %d\n", str, str, 0);
	printf("-------------------\n\n");

	return 0;
}