#include "shell.h"

#include <unistd.h>

int		ft_putcharb(int c)
{
	return (write(1, &c, 1));
}