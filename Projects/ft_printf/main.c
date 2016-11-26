#include "libft/libft.h"
#include <stdarg.h>

char *ft_printf(char *result, int numargs, ...)
{
	va_list args;
	int i;

	va_start(args, numargs);
	ft_strcpy(result, "");
	i = 0;
	while (i < numargs)
	{
		char *str = va_arg(args, char *);
		ft_strcat(result, str);
		i++;
	}
	va_end(args);
	return (result);
}

int count_flags(char *str)
{
	int i;
	int result;

	i = -1;
	result = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			++result;
		}
	}
	return (result);
}

int main(int ac, char **av)
{
	char result[100];
	(void)ac;
	(void)av;
	ft_putstr(ft_printf(result, 3, "bonjour", "les", "enfants\n"));
	ft_putnbr(count_flags("salut %      %      %    \n"));
	// ft_putstr(ft_printf(result, 3, "bonjour", "les", "enfants\n"));
	return (0);
}