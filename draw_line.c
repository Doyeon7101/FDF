/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:44:33 by dpark             #+#    #+#             */
/*   Updated: 2022/11/24 04:22:57 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// 넓이와 높이는 절대값으로 구해둠
void	bresenham(t_dot a, t_dot b, t_data *data, int argb)
{
	int	width = abs(a.x - b.x);
	int	height = abs(a.y - b.y);
	int	Yfactor = a.y < b.y ? -1 : 1;
	int	Xfactor = a.x < b.x ? -1 : 1;

	// 넓이가 높이보다 큰경우는 1,4,5,8 분면
	if (width > height)
	{
		int y = b.y;
		int det = (2 * height) - width; // 점화식
		for (int x = b.x; x != a.x; x += Xfactor)
		{
			if (det < 0) //판별
				det += 2 * height;
			else 
			{
 				y += Yfactor;
				det += (2 * height - 2 * width);
			}
			if (a.x > WIN_W_SIZE || a.y > WIN_H_SIZE || a.y < 0 || a.x < 0)
				return;
			mlx_pixel_put(data->mlx, data->win, x, y, argb);
		}
	}
	else
	{
		int x = b.x;
		int det2 = (2 * width) - height; // 점화식
		for (int y = b.y; y != a.y; y+= Yfactor)
		{
		if (det2 < 0)
			det2 += 2 * width;
 		else
		{
			x += Xfactor;
			det2 += (2 * width - 2 * height);
		}
			if (a.x > WIN_W_SIZE || a.y > WIN_H_SIZE || a.y < 0 || a.x < 0)
				return;
			mlx_pixel_put(data->mlx, data->win, x, y, argb);
		}
	}
}

int	create_argb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_by_dots(t_dot **matrix, t_data *data)
{
	int	l;
	int	x;
	int	y;

	x = -1;
	y = -1;
	l = 30;
	while (++y < data->h)
	{
		while (++x < data->w)
			update_dots(&matrix[y][x],l,0.523599, data);
		x= -1;
	}
	x = 0;
	y = -1;
	while (matrix[++y])
	{
		while (1)
		{
			if (matrix[y + 1])
				bresenham(matrix[y][x], matrix[y+1][x], data, create_argb(0, 0, 255, 0));
			if(x != data->w - 1)
				bresenham(matrix[y][x], matrix[y][x+1], data, create_argb(0, 0, 255, 0));
			else
				break ;
			x++;
		}
		x = 0;
	}


	return ;
}
