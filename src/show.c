#include "./include/so_long.h"


void	read_map(t_data	*data, t_map *map)
{
	data->counter = 0;
	//data->enemy->count = 0;
	map->h = 0;
	while (map->h < (data->height / IMG_HEIGHT))
	{
		map->w = 0;
		while (map->w < (data->width / IMG_WIDTH))
		{
			if (map->line[map->h][map->w] == '1')
				set_object(data, WALL);
			else if (map->line[map->h][map->w] == 'C')
				set_object(data, COLLECT);
			else if (map->line[map->h][map->w] == 'E')
				set_object(data, CLOSEDEXIT);
			else if (map->line[map->h][map->w] == 'A')
				set_object(data, ENEMY);
			else if (map->line[map->h][map->w] == 'P')
				set_player(data, PLAYER);
			help_read(data, map);
			map->w++;
		}
		map->h++;
	}
}

void	help_read(t_data *data, t_map *map)
{
	if (map->line[map->h][map->w] == 'E')
	{
		data->exit_x = map->w;
		data->exit_y = map->h;
	}
	else if (map->line[map->h][map->w] == 'A')
	{
		data->enemy->pos_x = map->w;
		data->enemy->pos_y = map->h;
	}
}