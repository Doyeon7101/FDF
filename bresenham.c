/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:08:25 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 19:17:57 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (-1 * i);
	return (i);
}

int	ft_factor(int a, int b)
{
	if (a < b)
		return (-1);
	return (1);
}

void	more_than_one(t_dot a, t_dot b, t_data *data)
{
	int	x;
	int	y;
	int	det;
	int	height;
	int	width;

	y = b.y;
	x = b.x;
	height = ft_abs(a.y - b.y);
	width = ft_abs(a.x - b.x);
	det = (2 * width) - height;
	while (y != a.y)
	{
		if (det < 0)
			det += 2 * width;
		else
		{
			x += data->xfactor;
			det += (2 * width - 2 * height);
		}
		if (a.x > WIN_W_SIZE || a.y > WIN_H_SIZE || a.y < 0 || a.x < 0)
			return ;
		mlx_pixel_put(data->mlx, data->win, x, y, a.color);
		y += data->yfactor;
	}
}

void	less_than_one(t_dot a, t_dot b, t_data *data)
{
	int	x;
	int	y;
	int	det;
	int	height;
	int	width;

	y = b.y;
	x = b.x;
	height = ft_abs(a.y - b.y);
	width = ft_abs(a.x - b.x);
	det = (2 * width) - height;
	while (x != a.x)
	{
		if (det < 0)
			det += 2 * height;
		else
		{
			y += data->yfactor;
			det += (2 * height - 2 * width);
		}
		if (a.x > WIN_W_SIZE || a.y > WIN_H_SIZE || a.y < 0 || a.x < 0)
			return ;
		mlx_pixel_put(data->mlx, data->win, x, y, a.color);
		x += data->xfactor;
	}
}

void	bresenham(t_dot a, t_dot b, t_data *data)
{
	int	width;
	int	height;

	width = ft_abs(a.x - b.x);
	height = ft_abs(a.y - b.y);
	data->xfactor = ft_factor(a.x, b.x);
	data->yfactor = ft_factor(a.y, b.y);
	if (width > height)
		less_than_one(a, b, data);
	else
		more_than_one(a, b, data);
}
