/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:39:31 by isibio            #+#    #+#             */
/*   Updated: 2023/05/03 11:39:32 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	parsing_map_empty(char **map)
{
	if (!map[0])
		return (error_message_map(10, "parsing_map_empty", 2, 1));
	return (0);
}

int	parsing_map_square(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (1);
		i++;
	}	
	return (0);
}

int	parsing_map_walls(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i][0] != WALL || map[i][ft_strlen(map[i]) - 1] != WALL)
			return (1);
		i++;
	}
	if (check_only_char(map[0], WALL))
		return (1);
	if (check_only_char(map[i - 1], WALL))
		return (1);
	return (0);
}

// to do : replace message errors by settings->error_massage
int	parsing_map_composition(char **map)
{
	int	errors;
	int	nb_elememts;

	errors = 0;
	nb_elememts = 0;
	if (map_count_char(map, EXIT) != 1)
		errors += parsing_map_err(20, "parsing_map_exit_reachable", 2, 1);
	if (map_count_char(map, PLAYER) != 1)
		errors += parsing_map_err(21, "parsing_map_exit_reachable", 2, 1);
	if (map_count_char(map, COLLECTIBLE) == 0)
		errors += parsing_map_err(22, "parsing_map_exit_reachable", 2, 1);
	nb_elememts += map_count_char(map, COLLECTIBLE);
	nb_elememts += map_count_char(map, EXIT);
	nb_elememts += map_count_char(map, PLAYER);
	nb_elememts += map_count_char(map, GROUND);
	nb_elememts += map_count_char(map, WALL);
	nb_elememts += map_count_char(map, '\n');
	if (nb_elememts != map_surface(map))
		errors += parsing_map_err(23, "parsing_map_exit_reachable", 2, 1);
	return (errors);
}

int	parsing_map_exit_reachable(char **map)
{
	int		errors;
	char	**map_virused;
	char	**map_tmp;
	char	virus;

	errors = 0;
	virus = PLAYER;
	map_virused = malloc(sizeof(char *) * (map_len(map) + 1));
	map_tmp = malloc(sizeof(char *) * (map_len(map) + 1));
	map_clone(map_virused, map);
	map_clone(map_tmp, map);
	while (map_virused != NULL)
	{
		map_virused = map_virus(map_virused, WALL, virus, virus);
		if (map_virused != NULL)
		{
			free_arr_arr(0, map_tmp);
			map_clone(map_tmp, map_virused);
		}
	}
	if (map_count_char(map_tmp, EXIT))
		errors += parsing_map_err(10, "parsing_map_exit_reachable", 2, 1);
	if (map_count_char(map_tmp, COLLECTIBLE))
		errors += parsing_map_err(11, "parsing_map_exit_reachable", 2, 1);
	return (free_arr_arr(1, map_tmp), errors);
}
