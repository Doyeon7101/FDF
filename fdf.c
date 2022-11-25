/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 03:42:08 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 20:13:47 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W_SIZE, WIN_H_SIZE, "FDF");
	mlx->img = mlx_new_image(mlx->mlx, WIN_W_SIZE, WIN_H_SIZE);
}

int	key_hook(int keycode, t_data *image)
{
	if (keycode == 53)
	{
		mlx_destroy_window(image->mlx, image->win);
		exit (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dot		**matrix;
	t_data		mlx;

	mlx.length = 25;
	if (argc != 2)
		ft_print_error("argc error");
	init_mlx(&mlx);
	matrix = make_matrix(*++argv, &mlx);
	draw_by_dots(matrix, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
