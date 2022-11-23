/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:58:48 by dpark             #+#    #+#             */
/*   Updated: 2022/11/23 21:06:15 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isomatic(t_dot *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}

void	shift_dots(t_dot *dot)
{
	dot->x += 1920 / 3;
	dot->y += 1280 / 3;
}

void	resizing_dots(t_dot *dot, int length)
{
	dot->x *= length;
	dot->y *= length;
	dot->z *= 10;
}

void	update_dots(t_dot *dot, int l, double theta)
{
	resizing_dots(dot, l);
	isomatic(dot, theta);
	shift_dots(dot);
}
