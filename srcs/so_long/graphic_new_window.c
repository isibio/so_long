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
