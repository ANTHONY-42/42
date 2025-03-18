#include <stdio.h>
#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	printf("HELLO SO_LONG !");
	t_mlx *mlx;
	t_data	img;

	mlx = malloc(sizeof(t_mlx *));
	if (!mlx)
		return (0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1280, 800, "Hello world!");
	img.img = mlx_new_image(mlx->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 600, 502, 0x0000FF0000);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_loop(mlx->mlx);

	return (0);
}
