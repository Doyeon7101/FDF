/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:44:33 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 16:48:44 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_by_dots(t_dot **matrix, t_data *data)
{
	int	x;
	int	y;

	update_dots(matrix, data->length, 0.52359, data);
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
