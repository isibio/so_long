/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:06:56 by isibio            #+#    #+#             */
/*   Updated: 2023/04/25 20:07:13 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	parsing_map(char **map)
{
	if (parsing_map_empty(map))
		return (error_message_map(10, 2), 1);
	if (parsing_map_square(map))
		return (error_message_map(11, 2), 1);
	if (parsing_map_walls(map))
		return (error_message_map(12, 2), 1);
	if (parsing_map_composition(map))
		return (error_message_map(13, 2), 1);
	if (parsing_map_exit_reachable(map))
		return (error_message_map(14, 2), 1);
	return (0);
}

void	error_message_map(int error_id, int fd)
{
	if (error_id == 10)
		ft_putstr_fd("[error_message_map] : Error, map is empty\n", fd);
	if (error_id == 11)
		ft_putstr_fd("[error_message_map] : Error, map is not a SQUARE\n", fd);
	if (error_id == 12)
		ft_putstr_fd("[error_message_map] : Error, map border is incorrect\n", fd);
	if (error_id == 13)
		ft_putstr_fd("[error_message_map] : Error, map composition is incorrect\n", fd);
	if (error_id == 14)
		ft_putstr_fd("[error_message_map] : Error, position of EXIT or COLLECTIBLE is incorrect\n", fd);
}
