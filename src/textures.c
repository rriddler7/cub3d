#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int x, int y)
{
	int	color;

	color = *(unsigned int *)(img->addr + (y * img->line_length + \
		x * (img->bits_per_pixel / 8)));
	return (color);
}

void	make_image(t_data *data, t_img *img)
{
	img->img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, \
		&img->bits_per_pixel, \
		&img->line_length, &img->endian);
}

void	get_textures(t_data *data)
{
	data->tex.no.img = mlx_xpm_file_to_image(data->mlx.mlx, data->no, \
		&data->tex.no.width, &data->tex.no.height);
	data->tex.no.addr = mlx_get_data_addr(data->tex.no.img, \
		&data->tex.no.bits_per_pixel, \
		&data->tex.no.line_length, &data->tex.no.endian);
	data->tex.ea.img = mlx_xpm_file_to_image(data->mlx.mlx, data->ea, \
		&data->tex.ea.width, &data->tex.ea.height);
	data->tex.ea.addr = mlx_get_data_addr(data->tex.ea.img, \
		&data->tex.ea.bits_per_pixel, \
		&data->tex.ea.line_length, &data->tex.ea.endian);
	data->tex.we.img = mlx_xpm_file_to_image(data->mlx.mlx, data->we, \
		&data->tex.we.width, &data->tex.we.height);
	data->tex.we.addr = mlx_get_data_addr(data->tex.we.img, \
		&data->tex.we.bits_per_pixel, \
		&data->tex.we.line_length, &data->tex.we.endian);
	data->tex.so.img = mlx_xpm_file_to_image(data->mlx.mlx, data->so, \
		&data->tex.so.width, &data->tex.so.height);
	data->tex.so.addr = mlx_get_data_addr(data->tex.so.img, \
		&data->tex.so.bits_per_pixel, \
		&data->tex.so.line_length, &data->tex.so.endian);
}
