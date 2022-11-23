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



// 넓이와 높이는 절대값으로 구해둠
void bresenham(t_dot a, t_dot b, t_data *image, int argb)
{
    int width = abs(a.x - b.x);
    int height = abs(a.y - b.y);
    int Yfactor = a.y < b.y ? -1 : 1;
    int Xfactor = a.x < b.x ? -1 : 1;

    // 넓이가 높이보다 큰경우는 1,4,5,8 분면
    if (width > height)
    {
     int y = b.y;
     int det = (2 * height) - width; // 점화식
     for (int x = b.x; x != a.x; x += Xfactor)
     {
      if (det < 0) //판별
  {
           det += 2 * height;
      }
      else 
  {
   y += Yfactor;
   det += (2 * height - 2 * width);
  }
    my_mlx_pixel_put(image, x, y, argb);
 }
}
else
{
 int x = b.x;
 int det2 = (2 * width) - height; // 점화식
 for (int y = b.y; y != a.y; y+= Yfactor)
 {
  if (det2 < 0)
  {
   det2 += 2 * width;
  }
  else
  {
   x += Xfactor;
   det2 += (2 * width - 2 * height);
  }
    my_mlx_pixel_put(image, x, y, argb);
 }
}
}



/**
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
**/

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
    l = 80; //return_best_length
    double theta = 0.98719785039579;
    while (++y < h)
    {
        while (++x < w)
            update_dots(&matrix[y][x],l, theta);
        x= -1;
    }
	x = 0;
    y = -1;
    int k = -1;
    int a = -1;
    while (matrix[++k])
    {
        while (++a < w)
            printf("x : %d, y : %d, z : %d\n", matrix[0][a].x, matrix[0][a].y, matrix[0][a].z);
    }

	while (matrix[++y])
	{
        while (1)
        {
		    if (matrix[y + 1])
                bresenham(matrix[y][x], matrix[y+1][x], data, create_argb(0,0,255,0));
            if(x != w-1)
                bresenham(matrix[y][x], matrix[y][x+1], data, create_argb(0, 0, 255, 0));
            else
			    break ;
		    x++;
        }
        x = 0;
	}

    return ;
}