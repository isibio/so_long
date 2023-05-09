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
	graphic_put_textures(data->texture, data->map, data->mlx_ptr, data->win_ptr);
	if (data->player.movements != movements)
		ft_printf("[control_key_management] movements : %d\n", data->player.movements);
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

//*****************************************************************************************************************************************
// * Déplace de 1 un char donné et remplace l'ancienne pos de character par un GROUND
//***
// * character	: le char qui va être remplacé
// * direction	: "up" "down" "left" "right"
// * collision	: ne pas effectuer le déplacement si un char "collision" se trouve sur la nouvelle pusition théorique de character
//***
// * return values :
// * return la map avec le character déplacé
// *
//***
// * errors :
// * si il y a plusieurs character sur la map, le déplacement ne sera pas fait et la fonction retournera 1
//*****************************************************************************************************************************************
t_data	*move_object(t_data *data, char character, char *direction, char collision)
{
	int			character_x;
	int			character_y;
	static int	exit_x;
	static int	exit_y;

	character_x = get_coordinates('x', data->map, character, 0);
	character_y = get_coordinates('y', data->map, character, 0);
	if (get_coordinates('x', data->map, EXIT, 0) >= 0)
		exit_x = get_coordinates('x', data->map, EXIT, 0);
	if (get_coordinates('y', data->map, EXIT, 0) >= 0)
		exit_y = get_coordinates('y', data->map, EXIT, 0);
	data->player.movements++;
	if (!ft_strncmp(direction, "up", 2) && data->map[character_y - 1][character_x] != collision)
		data->map[character_y - 1][character_x] = character;
	else if (!ft_strncmp(direction, "down", 4) && data->map[character_y + 1][character_x] != collision)
		data->map[character_y + 1][character_x] = character;
	else if (!ft_strncmp(direction, "right", 5) && data->map[character_y][character_x + 1] != collision)
		data->map[character_y][character_x + 1] = character;
	else if (!ft_strncmp(direction, "left", 4) && data->map[character_y][character_x - 1] != collision)
		data->map[character_y][character_x - 1] = character;
	else
		return (data->player.movements--, data);
	data->map[character_y][character_x] = GROUND;
	if (data->map[exit_y][exit_x] != PLAYER)
		data->map[exit_y][exit_x] = EXIT;
	else if (!map_count_char(data->map, COLLECTIBLE))
		game_end();
	return(data);
}














