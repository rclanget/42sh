#include <moulitest.h>
#include <string.h>
#include "shell.h"

t_env	*ft_savenv(char **tab);
void	ft_free_env(t_env *env);

static void test_env_normal(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_env *tmp;
	int	i = 0;

	test->debug = 1;
	tmp = ft_savenv(tab);
	if (!strcmp(tmp->var, "TEST1") && !strcmp(tmp->content, "content1") &&
		!strcmp(tmp->next->var, "TEST2") && !strcmp(tmp->next->content, "content2") &&
		!tmp->next->next)
		i++;
	ft_free_env(tmp);
	mt_assert(i);
}

static void test_env_null(t_test *test)
{
	char *tab[] = {NULL, NULL, NULL};
	t_env *tmp;
	int	i = 0;

	test->debug = 1;
	tmp = ft_savenv(tab);
	if (!tmp)
		i++;
	ft_free_env(tmp);
	mt_assert(i);
}

static void test_env_null2(t_test *test)
{
	char **tab = NULL;
	t_env *tmp;
	int	i = 0;

	test->debug = 1;
	tmp = ft_savenv(tab);
	if (!tmp)
		i++;
	ft_free_env(tmp);
	mt_assert(i);
}

static void test_content_null(t_test *test)
{
	char *tab[] = {"TEST1=", "TEST2=", NULL};
	t_env *tmp;
	int	i = 0;

	test->debug = 1;
	tmp = ft_savenv(tab);
	if (!strcmp(tmp->var, "TEST1") && !strcmp(tmp->content, "") &&
		!strcmp(tmp->next->var, "TEST2") && !strcmp(tmp->next->content, "") &&
		!tmp->next->next)
		i++;
	ft_free_env(tmp);
	mt_assert(i);
}

void    suite_test000_init_env(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_env_normal);
    SUITE_ADD_TEST(suite, test_env_null);
    SUITE_ADD_TEST(suite, test_env_null2);
    SUITE_ADD_TEST(suite, test_content_null);
}