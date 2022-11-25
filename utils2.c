/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:49:28 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 19:58:58 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_error(char *message)
{
	ft_putstr_fd(message, 1);
	exit(0);
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

void	check_array_size(char *file_name, int *x, int *y)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_print_error("open error");
	i = 0;
	*y = 0;
	line = get_next_line(fd);
	*x = func_chunk_cnt(line, ' ');
	while (line)
	{
		if (*x != (int)func_chunk_cnt(line, ' '))
			ft_print_error("invalid map size");
		(*y)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}
