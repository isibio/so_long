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
	return(0);
}

// Cette fonction initialise toutes les données avant de rentrer
// Dans la game_loop
// renvoie >0 si il y a un prblm
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
	mlx_loop(data.mlx_ptr);
}

void game_end()
{
	system("leaks so_long");
	exit(0);
}
