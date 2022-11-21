#include "fdf.h"

int create_argb(int t, int r, int g, int b)
{
  return (t << 24 | r << 16 | g << 8 | b);
}

void bresenham(t_dot c1, t_dot c2, t_data *image, int argb)
{
    t_dot now;
    int f; //판별식
    int dx;
    int dy;

    dx = c2.x - c1.x;
    dy = c2.y - c1.y;
    now.x = c1.x;
    now.y = c1.y;
    f = (2 * dy) - dx;
    while ((now.x)++ < c2.x)
    {
      if (f <= 0)
        f = f + (2 * dy);
      else
      {
        f = f + 2 * (dy - dx);
        (now.y)++;
      }
       my_mlx_pixel_put(image, now.x, now.y, argb);
    }
}
/**
 * - 정점간 최적거리 구하기
 * - 최적거리 바탕으로 간선 잇기
 * - 

int return_best_length(t_dot **matrix, int h, int w, int x, int y)
{
}
 **/

void update_dots(t_dot dot_a, t_dot dot_b, t_data *data)
{
    dot_a.x *= data->line_length;
    dot_a.y *= data->line_length;
    dot_b.x *= data->line_length;
    dot_b.x *= data->line_length;
}

void draw_by_dots(t_dot **matrix, t_data *data)
{
    int l;
    int x;
    int y;

    x = -1;
    y = -1;
    l = 40; // return_best_length
    y++;
    while (++y < data->h - 1)
    {
        while (++x < data->w - 1)
        {
            update_dots(matrix[y][x], matrix[x+1][y+1], data);
            bresenham(matrix[y][x], matrix[x+1][y+1], data->img, create_argb(0, 135,200,0));
        }
    }
    return;
}