/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:26:03 by isibio            #+#    #+#             */
/*   Updated: 2023/05/03 17:10:09 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	control_key_management(int key, t_data *data)
{
	int	movements;

	movements = data->player.movements;
	data = control_key_move(key, data);
	graphic_put_textures(data->texture, data->map,
		data->mlx_ptr, data->win_ptr);
	if (data->player.movements != movements)
		ft_printf("movements : %d\n", data->player.movements);
	return (0);
}

t_data	*control_key_move(int key, t_data *data)
{
	if (key == 126)
		data = move_object(data, PLAYER, "up", WALL);
	if (key == 124)
		data = move_object(data, PLAYER, "right", WALL);
	if (key == 125)
		data = move_object(data, PLAYER, "down", WALL);
	if (key == 123)
		data = move_object(data, PLAYER, "left", WALL);
	return (data);
}

t_data	*move_object(t_data *data, char c, char *d, char co)
{
	int			c_x;
	int			c_y;
	static int	exit_x;
	static int	exit_y;

	c_x = get_coordinates('x', data->map, c, 0);
	c_y = get_coordinates('y', data->map, c, 0);
	if (get_coordinates('x', data->map, EXIT, 0) >= 0)
		exit_x = get_coordinates('x', data->map, EXIT, 0);
	if (get_coordinates('y', data->map, EXIT, 0) >= 0)
		exit_y = get_coordinates('y', data->map, EXIT, 0);
	if (!ft_strncmp(d, "up", 2) && data->map[c_y - 1][c_x] != co)
		data->map[c_y - 1][c_x] = c;
	else if (!ft_strncmp(d, "down", 4) && data->map[c_y + 1][c_x] != co)
		data->map[c_y + 1][c_x] = c;
	else if (!ft_strncmp(d, "right", 5) && data->map[c_y][c_x + 1] != co)
		data->map[c_y][c_x + 1] = c;
	else if (!ft_strncmp(d, "left", 4) && data->map[c_y][c_x - 1] != co)
		data->map[c_y][c_x - 1] = c;
	else
		return (data);
	data->map[c_y][c_x] = GROUND;
	game_exit(data, exit_x, exit_y);
	return (data->player.movements++, data);
}
