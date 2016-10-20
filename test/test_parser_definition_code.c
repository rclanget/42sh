// gcc srcs/termcaps_readline/parser_definition_code.c srcs/termcaps_readline/parser_definition_code_get.c test/test_parser_definition_code.c libft/libft.a -Ilibft/includes -I./includes
#include <stdio.h>
#include "libft.h"
#include "parser.h"

int main(void)
{
	int *i;
	int len;
	char *str;

	str = ft_strdup("ls -l");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("\'ls\'-l");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("cat -e << STOP");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("cat -e < myFile; ls");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("ls -laH > myFile");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("cat -e myFile >> myNewFile");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("ls | cat -e > myFile || echo 1 && \"ls -la\"");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("cat -e > toto; \'ls -l\'");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup(">> >");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("ls >> > myFile");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("\'\'");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = NULL;
	printf("%s\n", NULL);
	i = definition_code(str);
	len = ft_strlen("\'\'");
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("\'ls >> > myFile\'");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("\'ls >> > myFile");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	str = ft_strdup("|ls >> > myFile");
	printf("%s\n", str);
	i = definition_code(str);
	len = ft_strlen(str);
	while (len--)
	{
		printf("%d", *i);
		i++;
	}
	printf("\n\n");
	free(str);

	return (1);
}
