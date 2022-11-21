/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 03:42:08 by dpark             #+#    #+#             */
/*   Updated: 2022/11/21 15:30:16 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /  8));
  *(unsigned int*)dst = color;
}


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
  t_dot c1, c2;

  if (argc != 2)
    ft_print_error("error1");
  
  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, 1280, 720, "FDF");
  image.img = mlx_new_image(vars.mlx, 1280, 720); // 이미지 객체 생성
  image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당

  make_matrix(*++argv, &image);
  // bresenham(c1, c2, &image, create_argb(0, rgb.r, rgb.g, rgb.b));
  draw_by_dots(matrix, &image);
  mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
  mlx_key_hook(vars.win, key_hook, &vars);
  mlx_loop(vars.mlx);
  return(0);
}

/**
<당신이 할것>
2. 파싱 받아오기
3. 파싱받아온 좌표 윈도우 크기에맞게 재배열
4. 이렇게 구한 정점을 대상으로 각 정점 사이를 잇는 간선 브래잰험 함수 이용해서 서로 잇기
1. 선형 보건법으로 그라데이션 색 구현
아직도 궁금쓰. z좌표는 표현을 어케하라는거?
**/