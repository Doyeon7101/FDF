/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:44:33 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 16:06:10 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_by_dots(t_dot **matrix, t_data *data)
{
	int	x;
	int	y;
	int l;

	x = -1;
	y = -1;
	l = 30;
	while (++y < data->h)
	{
		while (++x < data->w)
			update_dots(&matrix[y][x], l, 0.523599, data);
		x = -1;
	}
	x = 0;
	y = -1;
	while (matrix[++y])
	{
		while (1)
		{
			if (matrix[y + 1])
				bresenham(matrix[y][x], matrix[y + 1][x], data);
			if (x != data->w - 1)
				bresenham(matrix[y][x], matrix[y][x + 1], data);
			else
				break ;
			x++;
		}
		x = 0;
	}
	return ;
}
