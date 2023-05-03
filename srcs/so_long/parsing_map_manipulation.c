/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_manipulation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:42:15 by isibio            #+#    #+#             */
/*   Updated: 2023/05/03 11:42:16 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// map_virus : return a virused map
char	**map_virus(char **map, char to_keep, char to_replace, char virus)
{
	char	**map_virused;
	int		x;
	int		y;
	int		min_len;

	map_virused = malloc(sizeof(char *) * (map_len(map) + 1));
	map_clone(map_virused, map);
	min_len = 0;
	while (1)
	{
		x = get_coordinates('x', map, to_replace, min_len);
		y = get_coordinates('y', map, to_replace, min_len);
		if (min_len == map_surface(map) || x < 0 || y < 0)
			return (free_arr_arr(1, map), free_arr_arr(1, map_virused), NULL);
		map_virused = map_virus_draw_around(map_virused, x, y, WALL, virus);
		if (map_search_around(map, x, y, virus) + map_search_around(map, x, y, to_keep) != 4)
			break ;
		min_len++;
	}
	return (free_arr_arr(1, map), map_virused);
}

void	map_replace_char(char **map, char to_replace, char replace)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][i] == to_replace)
				map[i][j] = replace;
			j++;
		}
		i++;
	}
}

// Dessine un char (to_replace) autour et sur un point (défini par x et y) dans une map,
// Ne remplace pas les characteres to_keep
// retourne la map modifiée
char **map_virus_draw_around(char **map, int x, int y, char to_keep, char to_replce)
{
	if (map[y][x] != to_keep)
		map[y][x] = to_replce;
	if (map[y - 1][x] != to_keep)
		map[y - 1][x] = to_replce;
	if (map[y + 1][x] != to_keep)
		map[y + 1][x] = to_replce;
	if (map[y][x - 1] != to_keep)
		map[y][x - 1] = to_replce;
	if (map[y][x + 1] != to_keep)
		map[y][x + 1] = to_replce;
	return (map);
}

// clone a char ** from src to dest
int	map_clone(char **dest, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = malloc(sizeof(char) * ft_strlen(src[i]) + 1);
		ft_strlcpy(dest[i], src[i], ft_strlen(src[i]) + 1);
		i++;
	}
	dest[i] = NULL;
	return (1);
}
