#include "../mlx_linux/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixels;
	int	line_length;
	int	endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}
void	print_square(t_data img, int x, int y, int offset, int color)
{
	int	actual_x;
	int	actual_y;

	actual_x = offset;
	actual_y = offset;

	while (actual_x <= x + offset)
	{
		my_mlx_pixel_put(&img, actual_x, actual_y, color);
		my_mlx_pixel_put(&img, actual_x, y + offset, color);
		actual_x++;
	}
	while (actual_y <= y + offset)
	{	
		my_mlx_pixel_put(&img, offset, actual_y, color);
		my_mlx_pixel_put(&img, x + offset, actual_y, color);
		actual_y++;
	}
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello World");
	img.img = mlx_new_image(mlx, 640, 480);

	//We have to pass `bits_per_pixels`, `line_length` and `endian` by reference.
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	print_square(img, 300, 220, 5, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
