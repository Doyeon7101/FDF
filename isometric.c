#include "fdf.h"

void isomatic(t_dot *dot, double angle)
{
    dot->x = (dot->x - dot->y) * cos(angle);
    dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
    // printf("x : %d, y : %d, z : %d\n", dot->x, dot->y, dot->z);
}

void iso(int *x, int *y, int *z, double theta)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(theta);
    *y = -*z + (previous_x + previous_y) * sin(theta);
}

void shift_dots(t_dot *dot)
{
    dot->x += 1280/3;
    dot->y += 720/3;
}

void resizing_dots(t_dot *dot, int length)
{
    dot->x *= length;
    dot->y *= length;
    dot->z *= 7;
}

//isomatic theta : 0.523599
void update_dots(t_dot *dot, int l, double theta)
{
    resizing_dots(dot, l);
    isomatic(dot, theta);
    // iso(&dot->x, &dot->y, &dot->z, theta);
    shift_dots(dot);
}
