#include "./include/so_long.h"

/*int    key_value(int key)
{
    char c;
    
    c = key;
    write(1, &c, 1);
    write(1, "\n", 1);
    return (key);
}*/
int on_mouse_exit(t_data	*data)
{
	close_win(data);
	return (0);
}

void	render_win(t_data *data)
{
    //set_background(data);
    //read_map(data, data->map);
    mlx_hook(data->mlx_win, KEY_PRESSED, MASK, key_events, data);
    mlx_hook(data->mlx_win, MOUSE_PRESSED, MASK, on_mouse_exit, data);
	mlx_loop(data->mlx);
}

     