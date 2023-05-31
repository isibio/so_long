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
	int		s_x;
	int		s_y;

	s_x = TEXTURE_RESOLUTION * ft_strlen(map[0]);
	s_y = TEXTURE_RESOLUTION * map_len(map);
	win_ptr = mlx_new_window(mlx_ptr, s_x, s_y, "pain");
	return (win_ptr);
}

// m = mlx_ptr
// w = win_ptr
void	graphic_put_textures(t_textures t, char **map, void *m, void *w)
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
				mlx_put_image_to_window(m, w, t.wall_xpm, j * 64, i * 64);
			if (map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(m, w, t.coll_xpm, j * 64, i * 64);
			if (map[i][j] == EXIT)
				mlx_put_image_to_window(m, w, t.exit_xpm, j * 64, i * 64);
			if (map[i][j] == GROUND)
				mlx_put_image_to_window(m, w, t.ground_xpm, j * 64, i * 64);
			if (map[i][j] == PLAYER)
				mlx_put_image_to_window(m, w, t.player_xpm, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

t_textures	graphic_init_textures(void *mlx_ptr)
{
	t_textures	t;
	int			width;
	int			height;

	t.wall = "./textures/wall_unicolor.xpm";
	t.wall_xpm = mlx_xpm_file_to_image(mlx_ptr, t.wall, &width, &height);
	if (!t.wall_xpm)
		exit(error_message_data_init(10, "graphic_init_textures", 2, 1));
	t.coll = "./textures/collectible_unicolor.xpm";
	t.coll_xpm = mlx_xpm_file_to_image(mlx_ptr, t.coll, &width, &height);
	if (!t.coll_xpm)
		exit(error_message_data_init(10, "graphic_init_textures", 2, 1));
	t.ground = "./textures/grass_unicolor.xpm";
	t.ground_xpm = mlx_xpm_file_to_image(mlx_ptr, t.ground, &width, &height);
	if (!t.ground_xpm)
		exit(error_message_data_init(10, "graphic_init_textures", 2, 1));
	t.exit = "./textures/exit_unicolor.xpm";
	t.exit_xpm = mlx_xpm_file_to_image(mlx_ptr, t.exit, &width, &height);
	if (!t.exit_xpm)
		exit(error_message_data_init(10, "graphic_init_textures", 2, 1));
	t.player = "./textures/player_sus.xpm";
	t.player_xpm = mlx_xpm_file_to_image(mlx_ptr, t.player, &width, &height);
	if (!t.player_xpm)
		exit(error_message_data_init(10, "graphic_init_textures", 2, 1));
	return (t);
}
