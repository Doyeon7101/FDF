/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:04:29 by dpark             #+#    #+#             */
/*   Updated: 2022/11/24 03:25:42 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i++])
	{
		if (s[i] == (char)c)
			return (i);
	}
	return(-1);
}

int	ft_strjoin(char **dest, char *s2)
{
	int			i;
	int			j;
	char		*s1;
	char		*c;

	if (!(*dest))
		s1 = "";
	else
		s1 = *dest;
	c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!c)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		c[i] = s1[i];
	while (s2[++j])
		c[i + j] = s2[j];
	c[i + j] = '\0';
	if (*dest)
		free(*dest);
	*dest = c;
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int	ft_revers_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (n + 1 > 0)
	{
		if (s1[i] != s2[j])
			return (0);
		i--;
		j--;
		n--;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	r;
	int		i;

	r = 0;
	i = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' \
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		r *= 10;
		r += *str - 48;
		str++;
	}
	return (r * i);
}