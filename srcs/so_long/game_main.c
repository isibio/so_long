/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:40:09 by isibio            #+#    #+#             */
/*   Updated: 2023/05/03 12:50:45 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	game_main(char **map)
{
	t_data		data;
	void		*mlx_ptr;

	mlx_ptr = mlx_init();
	data = game_init(mlx_ptr, map);
	game_loop(data);
	return (0);
}

t_data	game_init(void *mlx_ptr, char **map)
{
	t_data		data;

	data = data_init(mlx_ptr, map);
	data.mlx_ptr = mlx_ptr;
	data.win_ptr = graphic_new_window(mlx_ptr, data.map);
	graphic_put_textures(data.texture, data.map, data.mlx_ptr, data.win_ptr);
	return (data);
}

void	game_loop(t_data data)
{
	mlx_key_hook(data.win_ptr, control_key_management, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, game_end, NULL);
	mlx_loop(data.mlx_ptr);
}

int	game_end(void)
{
	exit(0);
	return (0);
}

void	game_exit(t_data *data, int exit_x, int exit_y)
{
	if (data->map[exit_y][exit_x] != PLAYER)
		data->map[exit_y][exit_x] = EXIT;
	else if (!map_count_char(data->map, COLLECTIBLE))
		game_end();
}
