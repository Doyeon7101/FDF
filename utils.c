#include "fdf.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void ft_print_error(char *message)
{
    ft_putstr_fd(message, 1);
    exit(0);
}

int	ft_revers_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (n+1 > 0)
	{
		if (s1[i] != s2[j])
			return (0);
		i--;
		j--;
		n--;
	}
	return (1);
}