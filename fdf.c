/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 03:42:08 by dpark             #+#    #+#             */
/*   Updated: 2022/11/23 20:12:20 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int key_hook(int keycode, t_vars *vars)
{
  if(keycode == 53)
  {
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
  }
  return(0);
}

int main(int argc, char **argv)
{
  t_vars vars;
  t_data image;
  t_color rgb;
  t_dot **matrix;

  if (argc != 2)
    ft_print_error("error1");
  
  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, 1920, 1280, "FDF");
  image.img = mlx_new_image(vars.mlx, 1920, 1280); // 이미지 객체 생성
  image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당

  matrix = make_matrix(*++argv, &image);
  draw_by_dots(matrix, &image);
  mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
  mlx_key_hook(vars.win, key_hook, &vars);
  mlx_loop(vars.mlx);
  return(0);
}

/**
	while (matrix[++k])
	{
		while (++a < w)
			printf("x : %d, y : %d, z : %d\n", matrix[0][a].x, matrix[0][a].y, matrix[0][a].z);
	}
  **/