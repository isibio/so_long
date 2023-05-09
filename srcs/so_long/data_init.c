/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:31 by isibio            #+#    #+#             */
/*   Updated: 2023/05/03 16:16:27 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_data	data_init(void *mlx_ptr, char **map)
{
	t_data	data;

	data.texture = graphic_init_textures(mlx_ptr);
	data.map = malloc(sizeof(char *) * (map_len(map) + 1));
	map_clone(data.map, map);
	data.player.movements = 0;
	return (data);
}
