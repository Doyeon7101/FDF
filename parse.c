/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:46:05 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 19:59:23 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	**malloc_arry(int x, int y)
{
	t_dot	**new;

	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	if (!new)
		ft_print_error("malloc faild");
	return (new);
}

void	add_x_y_color(t_dot **matrix, char **z_value, t_data *data)
{
	char	**color_value;
	int		t;

	t = -1;
	while (++(data->xp) < data->x)
	{
		matrix[data->yp][data->xp].x = data->xp;
		matrix[data->yp][data->xp].y = data->yp;
		if (ft_strchr(z_value[data->xp], ',') > 0)
		{
			color_value = ft_split(z_value[data->xp], ',');
			matrix[data->yp][data->xp].z = atoi(color_value[++t]);
			matrix[data->yp][data->xp].color = \
							ft_atoi_base(color_value[++t], "0123456789ABCDEF");
			while (t-- > 0)
				free(color_value[t]);
		}
		else
		{
			matrix[data->yp][data->xp].z = ft_atoi(z_value[data->xp]);
			matrix[data->yp][data->xp].color = 0XFFFFFF;
		}
	}
}

void	add_to_matrix(char *file_name, t_dot **matrix, t_data *data)
{
	char	*line;
	char	**z_value;
	int		fd;

	data->xp = -1;
	data->yp = -1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_print_error("open error");
	while (++(data->yp) < data->y)
	{
		line = get_next_line(fd);
		z_value = ft_split(line, ' ');
		add_x_y_color(matrix, z_value, data);
		while ((data->xp)-- > 0)
			free(z_value[data->xp]);
		free(line);
	}
	matrix[data->y] = NULL;
	close(fd);
}

t_dot	**allocate_memory_for_matrix(char *file_name, int *x, int *y)
{
	t_dot	**new;

	check_array_size(file_name, x, y);
	new = malloc_arry(*x, *y);
	return (new);
}

t_dot	**make_matrix(char *file_name, t_data *data)
{
	t_dot	**matrix;

	if (!ft_revers_strncmp(file_name, ".fdf", 4))
		ft_print_error("Invalid extension name");
	matrix = allocate_memory_for_matrix(file_name, &(data->x), &(data->y));
	add_to_matrix(file_name, matrix, data);
	data->h = data->y;
	data->w = data->x;
	return (matrix);
}
