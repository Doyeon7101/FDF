/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:58:48 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 19:14:33 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isomatic(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	shift_dots(t_dot *dot, t_data *data)
{
	int	x_shift;
	int	y_shift;

	if (data->h > 70)
	{
		x_shift = (WIN_W_SIZE - data->w) / 6;
		y_shift = (WIN_H_SIZE - data->h) / 6;

	}
	x_shift = (WIN_W_SIZE - data->w) / 2;
	y_shift = (WIN_H_SIZE - data->h) / 2;
	dot->x += x_shift;
	dot->y += y_shift;
}

void	resizing_dots(t_dot *dot, int length, t_data *data)
{
	if (data->w > 100 || data->h > 50)
		length = 13;
	if (data->h > 70)
		length = 6;
	if (data->h > 180)
		length = 3;
	if (data->h > 500)
		ft_print_error("invalid map size");
	dot->x *= length;
	dot->y *= length;
	dot->z *= length;
}

void	update_dots(t_dot **matrix, int l, double theta, t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < data->h)
	{
		while (++x < data->w)
		{
			resizing_dots(&matrix[y][x], l, data);
			isomatic(&matrix[y][x], theta);
			shift_dots(&matrix[y][x], data);
		}
		x = -1;
	}
}
