/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 05:14:45 by dpark             #+#    #+#             */
/*   Updated: 2022/11/21 14:56:01 by dpark            ###   ########.fr       */
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
# define BUFFER_SIZE 500
#endif

typedef struct  s_data {
  void        *img;
  char        *addr;
  int         bits_per_pixel;
  int         line_length;
  int         endian;
}               t_data;

typedef struct s_dot{
  int x;
  int y;
  int z;
  int is_end;
}   t_dot;

typedef struct s_matrix{
  t_dot dot;
} t_matrix;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct s_color{
  int r;
  int g;
  int b;
}    t_color; 

//get next line utils
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strjoin(char **dest, char *s2);
int		ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

//utils
void ft_print_error(char *message);
void test_func(int i);
char	**ft_split(char const *s, char c);
size_t	func_chunk_cnt(char const *s, char c);
int	ft_revers_strncmp(const char *s1, const char *s2, size_t n);

#endif