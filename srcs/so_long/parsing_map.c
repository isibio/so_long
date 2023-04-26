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
	char	**tmp_map;
	char	virus;

	virus = 'v';
	tmp_map = map_virus(map, WALL, PLAYER, virus);
	//tmp_map = map_virus(tmp_map, WALL, 'v', virus);
	//tmp_map = map_virus(tmp_map, WALL, 'v', virus);
	//tmp_map = map_virus(tmp_map, WALL, 'v', virus);
	//tmp_map = map_virus(tmp_map, WALL, 'v', virus);
	//tmp_map = map_virus(tmp_map, WALL, 'v', virus);
	//tmp_map = map_virus(tmp_map, WALL, 'v', virus);
	return (0);
}

char	**map_virus(char **map, char to_keep, char to_replace, char virus)
{
	char	**map_virused;
	int		x;
	int		y;
	int i = 0;
	(void) to_keep;

	printf("map_len = %d\n", map_len(map));
	map_virused = malloc(sizeof(char *) * (map_len(map)));
	map_clone(map_virused, map);

////////////////////////////////////////////////////////////

	printf("y=%d\n", get_coordinates('y', map, to_replace, 0));
	printf("x=%d\n", get_coordinates('x', map, to_replace, 0));
	printf("%d\n", virus);

	x = get_coordinates('x', map, to_replace, 0);
	y = get_coordinates('y', map, to_replace, 0);

	//map_virused = map_virus_draw_around(map_virused, x, y, WALL, virus);
	i = 0;
	printf("\nmap_virused\n");
	while (map_virused[i])
	{
		printf("%s\n", map_virused[i]);
		i++;
	}
	/*i = 0;
	printf("map\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}*/
	return (map_virused);
}

// Dessine un char (virus) autour et sur un point (défini par x et y) dans une map,
// Ne remplace pas les characteres to_keep
// retourne la map modifiée
char **map_virus_draw_around(char **map, int x, int y, char to_keep, char virus)
{
	if (map[y][x] != to_keep)
		map[y][x] = virus;
	if (map[y - 1][x] != to_keep)
		map[y - 1][x] = virus;
	if (map[y + 1][x] != to_keep)
		map[y + 1][x] = virus;
	if (map[y][x - 1] != to_keep)
		map[y][x - 1] = virus;
	if (map[y][x + 1] != to_keep)
		map[y][x + 1] = virus;
	return (map);
}

// Donne la longeur d'une map (verticale)
int	map_len(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

// return les cos (x ou y (= orientation)) de c dans **map
// return -1 si pas trouvé
int	get_coordinates(char orientation, char **map, char c, int min_len)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c && i + j >= min_len)
			{
				if (orientation == 'x')
					return (j);
				if (orientation == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	map_clone(char **dest, char **src)
{
	int	i;
	//int	j;

	i = 0;
	while (src[i])
	{
		dest[i] = malloc(sizeof(char) * ft_strlen(src[i]));
		ft_strlcpy(dest[i], src[i], ft_strlen(src[i]) + 1);
		i++;
	}
	return (1);
}













