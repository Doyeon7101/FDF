#include "fdf.h"

void check_array_size(char *file_name, int *x, int *y)
{
    char *line;
    int i;
    int fd;

    if ((fd = open(file_name, O_RDONLY)) == -1)
        ft_print_error("open error");
    i = 0;
    *y = 0;
    line = get_next_line(fd);
    *x = func_chunk_cnt(line, ' ');
    while(line)
    {
        if (*x != func_chunk_cnt(line, ' '))
            ft_print_error("invalid map size");
        (*y)++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return ;
}

t_dot **malloc_arry(int x, int y)
{
    t_dot **new;

    new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1 ));
    while (y > 0)
        new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
    if (!new)
        ft_print_error("malloc faild");
    return(new);
}

void add_to_matrix(char *file_name, t_dot **matrix, int x, int y)
{
    char *line;
    char **z_value;
    int yp;
    int xp;
    int fd;
    
    yp = -1;
    xp = -1;
    if ((fd = open(file_name, O_RDONLY)) == -1)
        ft_print_error("open error");
    while (++yp < y)
    {
        line = get_next_line(fd);
        z_value = ft_split(line, ' ');
        while (++xp < x)
        {
            matrix[yp][xp].x = xp;
            matrix[yp][xp].y = yp;
            matrix[yp][xp].z = atoi(z_value[xp]);
            
        }
        while (xp-- > 0)
            free(z_value[xp]);
        free(line);
    }
        close(fd);
}

t_dot **allocate_memory_for_matrix(char *file_name, int *x, int *y, int fd)
{
    t_dot **new;

    check_array_size(file_name, x, y);
    new = malloc_arry(*x, *y);
    return(new);
}

t_dot **make_matrix(char *file_name, t_data *data)
{
    t_dot **matrix;
    char *line;
    int fd;
    int x;
    int y;

    if(!ft_revers_strncmp(file_name, ".fdf", 4))
        ft_print_error("Invalid extension name");
    matrix= allocate_memory_for_matrix(file_name, &x, &y, fd);
    add_to_matrix(file_name, matrix, x, y);
    data->h = y;
    data->w = x;
    return(matrix);
}