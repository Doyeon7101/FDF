#include "fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /  8));
  *(unsigned int*)dst = color;
}

double return_max(double a, double b)
{
    if (a > b)
        return(a);
    else
        return(b);
}
void	bresenham(t_dot a, t_dot b, t_data *image, int argb)
{
	double dx;
	double dy;
	double max;

	dx = b.x - a.x;
	dy = b.y - a.y;
	max = return_max(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
       my_mlx_pixel_put(image, a.x, a.y, argb);
		a.x += dx;
		a.y += dy;
		if (a.x > 1280 || a.y > 720 || a.y < 0 || a.x < 0)
			break ;
	}
} 

void update_dots(t_dot *dot, int length)
{
    dot->x *= length;
    dot->y *= length;
}

int create_argb(int t, int r, int g, int b)
{
  return (t << 24 | r << 16 | g << 8 | b);
}

void draw_by_dots(t_dot **matrix, t_data *data)
{
    int l;
    int x;
    int y;
    int h;
    int w;

    h = data->h;
    w = data->w;
    x = -1;
    y = -1;
    l = 40; // return_best_length
    while (++y < h)
    {
        while (++x < data->w)
            update_dots(&matrix[y][x],l);
        x= -1;
    }
    y = -1;
    x = -1;
    while (++y < h-1)
    {
        while ((++x < w-1))
        {
            bresenham(matrix[y][x], matrix[y][x+1], data, create_argb(0,102,255,178));
            bresenham(matrix[y][x], matrix[y+1][x], data, create_argb(0,102,255,178));
        }
        x = -1;
    }
    x = -1;
    y = -1;
    while (++x < w-1)
        bresenham(matrix[h-1][x], matrix[h-1][x+1], data, create_argb(0,102,255,178));
    while (++y < h-1)
        bresenham(matrix[y][w-1], matrix[y+1][w-1], data, create_argb(0,102,255,178));
    return;

}



/** note
    while (++y < data->h)
    {
        while (++x < data->w-1)
            update_dots(&matrix[y][x],l);
        x= -1;
    }
    y = -1;
    x = -1;
    while (++y < data->h)
    {
        while (++x < data->w - 1)
            bresenham(matrix[y][x], matrix[y][x+1], data, create_argb(0, 0,255,0));
        x = -1;
    }
    y = -1;
    x = -1;
    while (++x < data->w)
    {
        while (++y < data->h - 1)
            bresenham(matrix[y][x], matrix[y+1][x], data, create_argb(0, 0,255,0));
        y = -1;

**/