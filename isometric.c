/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:58:48 by dpark             #+#    #+#             */
/*   Updated: 2022/11/24 04:24:56 by dpark            ###   ########.fr       */
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
	int x_shift;
	int y_shift;

	x_shift = (WIN_W_SIZE - data->w) / 2;
	y_shift = (WIN_H_SIZE - data->h) / 2;
	dot->x += x_shift;
	dot->y += y_shift;
}

void	resizing_dots(t_dot *dot, int length)
{
	dot->x *= length;
	dot->y *= length;
	dot->z *= 10;
}

void	update_dots(t_dot *dot, int l, double theta, t_data *data)
{
	resizing_dots(dot, l);
	isomatic(dot, theta);
	shift_dots(dot, data);
}
