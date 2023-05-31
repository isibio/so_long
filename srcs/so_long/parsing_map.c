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
		return (error_message_map(10, "parsing_map", 2, 1));
	if (parsing_map_square(map))
		return (error_message_map(11, "parsing_map", 2, 1));
	if (parsing_map_walls(map))
		return (error_message_map(12, "parsing_map", 2, 1));
	if (parsing_map_composition(map))
		return (error_message_map(13, "parsing_map", 2, 1));
	if (parsing_map_exit_reachable(map))
		return (error_message_map(14, "parsing_map", 2, 1));
	return (0);
}

int	error_message_map(int error_id, char *p, int fd, int ret)
{
	if (error_id == 10)
		ft_fprintf(fd, "[%s] : Error, map is invalid\n", p);
	if (error_id == 11)
		ft_fprintf(fd, "[%s] : Error, map is not a SQUARE\n", p);
	if (error_id == 12)
		ft_fprintf(fd, "[%s] : Error, map border is incorrect\n", p);
	if (error_id == 13)
		ft_fprintf(fd, "[%s] : Error, map composition is incorrect\n", p);
	if (error_id == 14)
		ft_fprintf(fd, "[%s] : Error, backtracking error\n", p);
	if (error_id == 15)
		ft_fprintf(fd, "[%s] : Error, map extension\n", p);
	return (ret);
}

int	error_message_data_init(int error_id, char *p, int fd, int ret)
{
	if (error_id == 10)
		ft_fprintf(fd, "[%s] : Error, cannot open texture\n", p);
	return (ret);
}

int	parsing_map_err(int error_id, char *prefix, int fd, int ret)
{
	if (error_id == 10)
		ft_fprintf(fd, "[%s] : Error, EXIT not reachable\n", prefix);
	if (error_id == 11)
		ft_fprintf(fd, "[%s] : Error, COLLECTIBLE not reachable\n", prefix);
	if (error_id == 20)
		ft_fprintf(fd, "[%s] : Error, number of EXIT\n", prefix);
	if (error_id == 21)
		ft_fprintf(fd, "[%s] : Error, number of PLAYER\n", prefix);
	if (error_id == 22)
		ft_fprintf(fd, "[%s] : Error, number of COLLECTIBLE\n", prefix);
	if (error_id == 23)
		ft_fprintf(fd, "[%s] : Error, unknown element\n", prefix);
	return (ret);
}
