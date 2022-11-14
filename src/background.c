#include "./include/so_long.h"

void	set_background(t_data *data)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	data->img->background = mlx_xpm_file_to_image(data->mlx, BACKGROUND, &width, &height);
	while (++i < data->height / IMG_HEIGHT)
	{
		j = -1;
		while (++j < data->width / IMG_WIDTH)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->background, j * IMG_WIDTH, i * IMG_HEIGHT);
	}
}

//clear last img
int	reset_background(int w, int h, t_data *data)
{
	int	i;
	int	j;

	i = h * IMG_HEIGHT;
	j = w * IMG_WIDTH;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->background, j, i);
	return (0);
}


// set image objects on window
void	set_object(t_data *data, char *path)
{
	int	width;
	int	height;

	data->img->object = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->object, (data->map->w * IMG_WIDTH), (data->map->h * IMG_HEIGHT));
}

//place player on window
void	set_player(t_data *data, char *path)
{
	int	width;
	int	height;

	data->pos_x = data->map->w;
	data->pos_y = data->map->h;
	data->img->sprite = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->sprite, (data->pos_x * IMG_WIDTH), (data->pos_y * IMG_HEIGHT));
}