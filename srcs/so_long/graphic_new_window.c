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
	int	size_x;
	int	size_y;

	size_x = TEXTURE_RESOLUTION * ft_strlen(map[0]);
	size_y = TEXTURE_RESOLUTION * map_len(map);
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "### placeholder title defined in graphic_new_window()### ");
	return (win_ptr);
}

void	graphic_put_textures(t_textures texture, char **map, void *mlx_ptr, void *win_ptr)
{
	(void) texture;
	(void) map;
	(void) mlx_ptr;
	(void) win_ptr;
	void	*wall_ptr;
	void	*collectible_ptr;
	void	*exit_ptr;
	void	*ground_ptr;
	int		width;
	int		height;
	int		i;
	int		j;

	wall_ptr		= mlx_xpm_file_to_image(mlx_ptr, texture.wall, &width, &height);
	collectible_ptr	= mlx_xpm_file_to_image(mlx_ptr, texture.collectible, &width, &height);
	exit_ptr		= mlx_xpm_file_to_image(mlx_ptr, texture.exit, &width, &height);
	ground_ptr		= mlx_xpm_file_to_image(mlx_ptr, texture.ground, &width, &height);

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == WALL)
				mlx_put_image_to_window(mlx_ptr, win_ptr, wall_ptr, j * 64, i * 64);
			if (map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(mlx_ptr, win_ptr, collectible_ptr, j * 64, i * 64);
			if (map[i][j] == EXIT)
				mlx_put_image_to_window(mlx_ptr, win_ptr, exit_ptr, j * 64, i * 64);
			if (map[i][j] == GROUND)
				mlx_put_image_to_window(mlx_ptr, win_ptr, ground_ptr, j * 64, i * 64);
			j++;
		}
		i++;
	}
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 64, 64);
}

t_textures	graphic_init_textures()
{
	t_textures texture;
	texture.wall = "./textures/wall_unicolor.xpm";
	texture.player = "./textures/player_unicolor.xpm";
	texture.collectible = "./textures/collectible_unicolor.xpm";
	texture.ground = "./textures/grass_unicolor.xpm";
	texture.exit = "./textures/exit_unicolor.xpm";

	return (texture);
}