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
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	game_init(mlx_ptr, map);
	return(0);
}

// Cette fonction initialise toutes les données avant de rentrer
// Dans la game_loop
// renvoie >0 si il y a un prblm
int	game_init(void *mlx_ptr, char **map)
{
	t_data	data;
	data = data_init(mlx_ptr, map);
	void	*win_ptr;
	win_ptr = graphic_new_window(mlx_ptr, map);
	graphic_put_textures(data.texture, map, mlx_ptr, win_ptr);
	game_loop(mlx_ptr, win_ptr, &data);
	return (0);
}

void	game_loop(void *mlx_ptr, void *win_ptr,  t_data *data)
{
	mlx_key_hook(win_ptr, control_key_management, data);
	mlx_loop(mlx_ptr);
}
