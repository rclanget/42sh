#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// gcc srcs/tools/strsplitcustom.c test/test_strsplitcustom.c -L libft -l ft -I libft/includes

char			**cust_split(char *str);

int main(void) {
	char **tab;
	char **tmp;

	printf("--------\n");

	tab = cust_split("1 2 3");
	tmp = tab;
	while (*tmp) {
		printf("%s\n", *tmp);
		++tmp;
		free(*(tmp - 1));
	}
	free(tab);

	printf("--------\n");

	tab = cust_split(" 1 2 3 ");
	tmp = tab;
	while (*tmp) {
		printf("%s\n", *tmp);
		++tmp;
		free(*(tmp - 1));
	}
	free(tab);

	printf("--------\n");

	tab = cust_split("' 1 2 '3 ");
	tmp = tab;
	while (*tmp) {
		printf("%s\n", *tmp);
		++tmp;
		free(*(tmp - 1));
	}
	free(tab);

	printf("--------\n");

	tab = cust_split("' 1 '2 3 ");
	tmp = tab;
	while (*tmp) {
		printf("%s\n", *tmp);
		++tmp;
		free(*(tmp - 1));
	}
	free(tab);

	printf("--------\n");

	tab = cust_split(" '1' 2 3 ");
	tmp = tab;
	while (*tmp) {
		printf("%s\n", *tmp);
		++tmp;
		free(*(tmp - 1));
	}
	free(tab);

	printf("--------\n");

	tab = cust_split(" '1' 2' 3 ");
	tmp = tab;
	while (*tmp) {
		printf("%s\n", *tmp);
		++tmp;
		free(*(tmp - 1));
	}
	free(tab);

	printf("--------\n");

	sleep(10);
}
