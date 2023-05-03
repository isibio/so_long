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
	printf("input key : %d\n", key);
	control_key_move(key, data);
	return (0);
}

void	control_key_move(int key, t_data *data)
{
	if (key == 126)
		move_object(data->map, PLAYER, "up", WALL);
	if (key == 124)
		move_object(data->map, PLAYER, "right", WALL);
	if (key == 125)
		move_object(data->map, PLAYER, "down", WALL);
	if (key == 123)
		move_object(data->map, PLAYER, "left", WALL);
}

//*****************************************************************************************************************************************
// * Déplace de (1 * TEXTURE_RESOLUTION) un char donné et remplace l'ancienne pos de character par un GROUND
//***
// * character	: le char qui va être remplacé
// * direction	: "up" "down" "left" "right"
// * to_replace	: avec quel char remplacer l'ancienne pos de character
// * collision	: ne pas effectuer le déplacement si un char "collision" se trouve sur la nouvelle pusition théorique de character
//***
// * return values :
// * si le déplacement n'a pas pu être effectuer il renvoie 1
// * sinon il renvoie 0
//***
// * errors :
// * si il y a plusieurs character sur la map, le déplacement ne seta pas fait et la fonction retournera 1
//*****************************************************************************************************************************************
int move_object(char **map, char character, char *direction, char collision)
{
	printf("here\n");
	(void) collision;
	int	old_pos_character_x;
	int	old_pos_character_y;

	old_pos_character_x = get_coordinates('x', map, character, 0);
	old_pos_character_y = get_coordinates('y', map, character, 0);
	printf("%s\n", direction);
	return (0);
}
