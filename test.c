#include "so_long.h"


#include <math.h>
#include <stdio.h>

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    if (x < 0 || y < 0 || x >= 800 || y >= 600) // Boundary check
        return;
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_square(t_data *img, int x, int y, int size, int color)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            my_mlx_pixel_put(img, x + j, y + i, color);
        }
    }
}

void draw_circle(t_data *img, int xc, int yc, int radius, int color)
{
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if (x * x + y * y <= radius * radius)
                my_mlx_pixel_put(img, xc + x, yc + y, color);
        }
    }
}

void draw_triangle(t_data *img, int x, int y, int height, int color)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            my_mlx_pixel_put(img, x + j, y + i, color);
            my_mlx_pixel_put(img, x - j, y + i, color);
        }
    }
}

void draw_gradient(t_data *img)
{
    for (int y = 0; y < 600; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            int red = (x * 255) / 800;
            int green = (y * 255) / 600;
            int blue = ((x + y) * 255) / 1400;
            int color = (red << 16) | (green << 8) | blue;
            my_mlx_pixel_put(img, x, y, color);
        }
    }
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    if (!mlx)
        return (printf("Failed to initialize MiniLibX\n"), 1);
    mlx_win = mlx_new_window(mlx, 800, 600, "Shapes and Effects");
    if (!mlx_win)
        return (printf("Failed to create a window\n"), 1);

    img.img = mlx_new_image(mlx, 800, 600);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // Draw gradient background
    draw_gradient(&img);

    // Draw shapes
    draw_square(&img, 100, 100, 100, 0x00FF0000); // Red square
    draw_circle(&img, 400, 300, 50, 0x0000FF00);  // Green circle
    draw_triangle(&img, 700, 500, 50, 0x000000FF); // Blue triangle

    // Push image to the window
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    mlx_loop(mlx);
    return (0);
}
