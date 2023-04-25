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
	int	errors;

	errors = 0;
	errors += parsing_map_square(map);
	errors += parsing_map_walls(map);
	errors += parsing_map_composition(map);
	errors += parsing_map_exit_reachable(map);
	return (errors);
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
		if (map[i][0] != WALL && map[i][ft_strlen(map[i])] != WALL)
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

	errors = 0;
	if (count_char(map, EXIT) != 1)
	{
		errors++;
		ft_putstr_fd("[parsing_map_composition] : Error, number of EXIT\n", 2);
	}	
	if (count_char(map, PLAYER) != 1)
	{
		errors++;
		ft_putstr_fd("[parsing_map_composition] : Error, number of PLAYER\n", 2);
	}	
	if (count_char(map, COLLECTIBLE) == 0)
	{
		errors++;
		ft_putstr_fd("[parsing_map_composition] : Error, number of COLLECTIBLE\n", 2);
	}	
	return (errors);
}

int	parsing_map_exit_reachable(char **map)
{
	char **tmp_map;

	tmp_map = map_virus(map, WALL, 'x');
	// while
}

char	**map_virus(char **map, char to_keep, char to_replace)
{
	char	**map_virused;

	// prends les cos de tous les to_replace et remplace par to_replace à x + 1, x - 1, y + 1, y - 1
	return (map_virused);
}


// return les cos (x ou y (= orientation)) de c dans **map
// return NULL si pas trouvé
int	get_coordinates(char orientation, char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				if (orientation == 'x')
					return (j);
				if (orientation == 'y')
					return (x);
			}
			j++;
		}
		i++;
	}
}














