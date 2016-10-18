#include <moulitest.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char		*ft_trim(char *str);

static void simpleString_return(t_test *test)
{
	char *tmp;
	char *tmp1;

	// test->debug = 1;
	tmp1 = strdup("le tdd c'est cool");
	tmp = ft_trim(tmp1);
	// printf("%s\n", tmp);
	mt_assert(strcmp(tmp, "le tdd c'est cool") == 0);
	free(tmp);
}

static void string_space_within(t_test *test)
{
	char *tmp;
	char *tmp1;

	tmp1 = strdup("le       tdd       c'est       cool");
	tmp = ft_trim(tmp1);
	mt_assert(strcmp(tmp, "le tdd c'est cool") == 0);
	free(tmp);
}

static void string_tab_within(t_test *test)
{
	char *tmp;
	char *tmp1;

	tmp1 = strdup("le			tdd			c'est		cool");
	tmp = ft_trim(tmp1);
	mt_assert(strcmp(tmp, "le tdd c'est cool") == 0);
	free(tmp);
}

static void string_mix_within(t_test *test)
{
	char *tmp;
	char *tmp1;

	tmp1 = strdup("le	    	tdd		   	c'est	   	cool");
	tmp = ft_trim(tmp1);
	mt_assert(strcmp(tmp, "le tdd c'est cool") == 0);
	free(tmp);
}

static void string_trimtest_space(t_test *test)
{
	char *tmp;
	char *tmp1;

	// test->debug = 1;
	tmp1 = strdup("    le	    	tdd		   	c'est	   	cool     ");
	tmp = ft_trim(tmp1);
	// printf("[%s]\n", tmp);
	mt_assert(strcmp(tmp, "le tdd c'est cool") == 0);
	free(tmp);
}

static void string_trimtest_tab(t_test *test)
{
	char *tmp;
	char *tmp1;

	tmp1 = strdup("		le	    	tdd		   	c'est	   	cool		");
	tmp = ft_trim(tmp1);
	mt_assert(strcmp(tmp, "le tdd c'est cool") == 0);
	free(tmp);
}

static void string_trimtest_mix(t_test *test)
{
	char *tmp;
	char *tmp1;

	tmp1 = strdup("	    	le	    	tdd		   	c'est	   	cool	     	");
	tmp = ft_trim(tmp1);
	mt_assert(strcmp(tmp, "le tdd c'est cool") == 0);
	free(tmp);
}

static void string_null(t_test *test)
{
	char *tmp;
	
	tmp = ft_trim(NULL);
	mt_assert(!tmp);
}

void    suite_test100_ft_cleanline(t_suite *suite)
{
    SUITE_ADD_TEST(suite, simpleString_return);
    SUITE_ADD_TEST(suite, string_space_within);
    SUITE_ADD_TEST(suite, string_tab_within);
    SUITE_ADD_TEST(suite, string_mix_within);
    SUITE_ADD_TEST(suite, string_trimtest_space);
    SUITE_ADD_TEST(suite, string_trimtest_tab);
    SUITE_ADD_TEST(suite, string_trimtest_mix);
    SUITE_ADD_TEST(suite, string_null);
}
