/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 05:14:45 by dpark             #+#    #+#             */
/*   Updated: 2022/11/25 15:32:12 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#define WIN_W_SIZE 2560 //full screen
#define WIN_H_SIZE 1400
#endif

typedef struct  s_data{
  void        *img;
  int         h;
  int         w;
  void        *mlx;
  void        *win;
  double      theta;
  int         xfactor;
  int         yfactor;
}   t_data;

typedef struct s_dot{
  int x;
  int y;
  int z;
  int color;

}   t_dot;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct s_color{
  int r;
  int g;
  int b;
}    t_color; 

void my_mlx_pixel_put(t_data *data, int x, int y, int color);
//parsing
t_dot **make_matrix(char *file_name, t_data *data);
//get next line utils
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strjoin(char **dest, char *s2);
int		ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

//draw_line
void draw_by_dots(t_dot **matrix, t_data *data);
void update_dots(t_dot *dot, int l, double theta, t_data *data);
void	bresenham(t_dot a, t_dot b, t_data *data);

//utils
void ft_print_error(char *message);
void test_func(int i);
char	**ft_split(char const *s, char c);
size_t	func_chunk_cnt(char const *s, char c);
int	ft_revers_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
int	ft_sstrchr(const char *s, int c);
int	ft_atoi_base(char *str, char *base);

#endif