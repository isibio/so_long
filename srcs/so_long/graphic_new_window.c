/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_new_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:38:51 by isibio            #+#    #+#             */
/*   Updated: 2023/05/03 12:39:01 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*graphic_new_window(void *mlx_ptr, char **map)
{
	void	*win_ptr;
	int		size_x;
	int		size_y;

	size_x = TEXTURE_RESOLUTION * ft_strlen(map[0]);
	size_y = TEXTURE_RESOLUTION * map_len(map);
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "### placeholder title defined in graphic_new_window()### ");
	return (win_ptr);
}

void	graphic_put_textures(t_textures texture, char **map, void *mlx_ptr, void *win_ptr)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == WALL)
				mlx_put_image_to_window(mlx_ptr, win_ptr, texture.wall_xpm, j * 64, i * 64);
			if (map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(mlx_ptr, win_ptr, texture.collectible_xpm, j * 64, i * 64);
			if (map[i][j] == EXIT)
				mlx_put_image_to_window(mlx_ptr, win_ptr, texture.exit_xpm, j * 64, i * 64);
			if (map[i][j] == GROUND)
				mlx_put_image_to_window(mlx_ptr, win_ptr, texture.ground_xpm, j * 64, i * 64);
			if (map[i][j] == PLAYER)
				mlx_put_image_to_window(mlx_ptr, win_ptr, texture.player_xpm, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

t_textures	graphic_init_textures(void *mlx_ptr)
{
	int		width;
	int		height;
	void	*wall_ptr;
	void	*collectible_ptr;
	void	*exit_ptr;
	void	*ground_ptr;
	void	*player_ptr;

	t_textures texture;
	texture.wall = "./textures/wall_unicolor.xpm";
	wall_ptr = mlx_xpm_file_to_image(mlx_ptr, texture.wall, &width, &height);
	texture.wall_xpm = wall_ptr;
	texture.collectible = "./textures/collectible_unicolor.xpm";
	collectible_ptr	= mlx_xpm_file_to_image(mlx_ptr, texture.collectible, &width, &height);
	texture.collectible_xpm = collectible_ptr;
	texture.ground = "./textures/grass_unicolor.xpm";
	ground_ptr = mlx_xpm_file_to_image(mlx_ptr, texture.ground, &width, &height);
	texture.ground_xpm = ground_ptr;
	texture.exit = "./textures/exit_unicolor.xpm";
	exit_ptr = mlx_xpm_file_to_image(mlx_ptr, texture.exit, &width, &height);
	texture.exit_xpm = exit_ptr;
	texture.player = "./textures/player_sus.xpm";
	player_ptr = mlx_xpm_file_to_image(mlx_ptr, texture.player, &width, &height);
	texture.player_xpm = player_ptr;
	return (texture);
}
